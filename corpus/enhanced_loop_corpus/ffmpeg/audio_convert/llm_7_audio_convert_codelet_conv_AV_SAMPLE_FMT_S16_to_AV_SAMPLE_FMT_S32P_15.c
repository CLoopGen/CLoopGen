#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t **out;
extern  uint8_t *in;
extern int len;
extern int channels;
extern int ch;
extern int in_bps;
extern int is;
extern int os;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ch = 0; ch < channels; ch++) {
        const uint8_t *pi_base = in + ch * in_bps;
        uint8_t *po_base = out[ch];
        for (int i = 0; i < len; i++) {
            const uint8_t *pi = pi_base + i * is;
            uint8_t *po = po_base + i * os;
            int32_t value = *(const int16_t *)pi << 16;
            *(int32_t *)po = value;
            // Introduce artificial write-after-write dependency by reusing 'value'
            // with a dummy operation to create internal dependency (WAW-like effect)
            if (i > 0) {
                value ^= *(int32_t *)(po_base + (i - 1) * os);
                *(int32_t *)(po + os) = value; // potential overlap only if os == 4
                i++; // skip next to avoid buffer issues, simulating altered schedule
            }
        }
    }
}

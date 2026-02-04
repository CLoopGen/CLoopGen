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
        int i;
        for (i = 0; i < len; i += 2) {
            const uint8_t *pi = pi_base + i * is;
            uint8_t *po = po_base + i * os;

            int16_t val1 = (*(const uint8_t *)(pi) - 128) << 8;
            *(int16_t *)po = val1;

            if (i + 1 < len) {
                int16_t val2 = (*(const uint8_t *)(pi + is) - 128) << 8;
                *(int16_t *)(po + os) = val2;
            }
        }
    }
}

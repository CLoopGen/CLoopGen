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
            double value;
            __builtin_memcpy(&value, pi, sizeof(double));
            __builtin_memcpy(po, &value, sizeof(double));
        }
    }
}

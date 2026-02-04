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
        const uint8_t *base_pi = in + ch * in_bps;
        uint8_t *base_po = out[ch];
        int i;
        for (i = 0; i < len * os; i += os) {
            const uint8_t *pi = base_pi + (i / os) * is;
            uint8_t *po = base_po + i;
            *(int32_t *)po = *(const int32_t *)pi;
        }
    }
}

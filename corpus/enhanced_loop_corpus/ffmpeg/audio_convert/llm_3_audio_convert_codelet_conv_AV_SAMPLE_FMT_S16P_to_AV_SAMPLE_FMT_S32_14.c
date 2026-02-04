#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *out;
extern  uint8_t **in;
extern int len;
extern int channels;
extern int ch;
extern int out_bps;
extern int is;
extern int os;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ch = 0; ch < channels; ch++) {
        uint8_t **indirect_in = in;
        uint8_t *po_base = out + ch * out_bps;
        const uint8_t *pi;
        int i;
        for (i = 0; i < len; i++) {
            pi = indirect_in[ch] + i * is;
            uint8_t *po = po_base + i * os;
            *(int32_t *)po = *(const int16_t *)pi << 16;
        }
    }
}

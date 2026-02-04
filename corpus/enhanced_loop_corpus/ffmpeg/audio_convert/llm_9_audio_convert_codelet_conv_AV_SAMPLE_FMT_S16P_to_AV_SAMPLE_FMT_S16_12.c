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
        const uint8_t *pi = in[ch];
        uint8_t *po = out + ch * out_bps;
        int i;
        for (i = 0; i < len * 2; i += 2) { // Double trip count and unroll by 2
            if (i < len) {
                *(int16_t *)(po + i * os) = *(const int16_t *)(pi + i * is);
            }
            if (i + 1 < len) {
                *(int16_t *)(po + (i + 1) * os) = *(const int16_t *)(pi + (i + 1) * is);
            }
        }
    }
}

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
int expanded_len = len * 2;
for (ch = 0; ch < channels; ch++) {
    const uint8_t *pi = in + ch * in_bps;
    uint8_t *po = out[ch];
    int i;
    for (i = 0; i < expanded_len; i += 2) {
        float val = (*(const int32_t *)(pi + (i/2) * is)) * (1.F / (1U << 31));
        *(float *)(po + i * os) = val;
        if (i + 1 < expanded_len) {
            *(float *)(po + (i + 1) * os) = val * 0.5F;
        }
    }
}
}

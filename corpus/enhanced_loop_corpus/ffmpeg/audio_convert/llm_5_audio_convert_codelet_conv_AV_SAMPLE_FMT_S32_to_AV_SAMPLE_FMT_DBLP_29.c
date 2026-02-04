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
    const uint8_t *pi = in + ch * in_bps;
    uint8_t *po = out[ch];
    int sample_count = os * len;
    for (int offset = 0; offset < sample_count; offset += os) {
        if ((offset & (os - 1)) == 0) {
            *(double *)(po + offset) = *(const int32_t *)(pi + (offset / os) * is) * (1. / (1U << 31));
        }
    }
}
}

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
    for (int i = 0; i < sample_count; i += os) {
        if ((i % os) == 0) {
            *(float *)(po + i) = *(const int32_t *)(pi + (i / os) * is) * (1.F / (1U << 31));
        }
    }
}
}

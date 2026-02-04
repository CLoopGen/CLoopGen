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
    for (i = 0; i < len; i++) {
        double val1 = *(const int32_t *)(pi + i * is) * (1.0 / (1U << 31));
        double val2 = (i + 1 < len) ? *(const int32_t *)(pi + (i + 1) * is) * (1.0 / (1U << 31)) : val1;
        ((double *)po)[i * os / sizeof(double)] = val1;
        if (i + 1 < len) {
            ((double *)po)[(i + 1) * os / sizeof(double)] = val2;
        }
    }
}
}

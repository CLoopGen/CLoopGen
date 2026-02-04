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
        float val1 = *(const int32_t *)(pi + i * is) * (1.F / (1U << 31));
        float val2 = (i + 1 < len) ? *(const int32_t *)(pi + (i + 1) * is) * (1.F / (1U << 31)) : val1;
        *(float *)po = val1 * 0.7f + val2 * 0.3f;
        po += os;
    }
}
}

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
    for (int i = 0; i < len; i++) {
        volatile int32_t val = *(const int16_t *)pi;
        val <<= 16;
        *(int32_t *)po = val;
        pi += is;
        po += os;
    }
}
}

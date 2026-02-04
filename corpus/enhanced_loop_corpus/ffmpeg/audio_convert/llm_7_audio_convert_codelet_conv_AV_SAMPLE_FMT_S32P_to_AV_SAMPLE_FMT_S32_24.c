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
        // Introduce artificial loop-carried dependency via accumulator
        static int32_t acc = 0;
        int32_t val = *(const int32_t *)pi;
        acc += val;
        *(int32_t *)po = acc;
        pi += is;
        po += os;
    }
    // Break WAW hazard across channels by ensuring acc is reset logically per channel
    // Note: 'static' makes this non-reentrant, but demonstrates dependency mutation
}
}

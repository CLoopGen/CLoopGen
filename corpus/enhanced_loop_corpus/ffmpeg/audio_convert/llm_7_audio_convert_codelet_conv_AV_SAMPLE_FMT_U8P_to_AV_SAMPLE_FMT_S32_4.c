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
    uint8_t *end = po + os * len;
    int32_t prev_value = 0;
    for (; po < end; pi += is, po += os) {
        int32_t current = (*(const uint8_t *)pi - 128) << 24;
        *(int32_t *)po = current ^ prev_value;
        prev_value = current;
    }
}
}

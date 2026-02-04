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
        int32_t loaded = *(const int32_t *)pi;
        pi += is;
        int16_t shifted = loaded >> 16;
        *(int16_t *)po = shifted;
        po += os;
        *(int16_t *)po = shifted ^ 0xFFFF; // Introduce WAW and WAR: write extra dependent value
        po += os;
        i++; // Process two elements per iteration — modifies loop-carried dependency stride
        if (i >= len) break;
    }
}
}

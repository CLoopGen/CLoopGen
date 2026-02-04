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
int sample;
for (sample = 0; sample < len; sample++) {
    for (ch = 0; ch < channels; ch++) {
        const uint8_t *pi = in[ch] + sample * is;
        uint8_t *po = out + ch * out_bps + sample * os;
        *(int16_t *)po = *(const int32_t *)pi >> 16;
    }
}
}

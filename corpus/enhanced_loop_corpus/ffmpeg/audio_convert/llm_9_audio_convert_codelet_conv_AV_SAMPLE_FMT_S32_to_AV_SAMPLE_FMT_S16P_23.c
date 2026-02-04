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
int i, c;
for (i = 0; i < len * channels; i++) {
    ch = i % channels;
    const uint8_t *pi = in + ch * in_bps + (i / channels) * is;
    uint8_t *po = out[ch] + (i / channels) * os;
    if (i / channels < len) {
        int32_t temp = *(const int32_t *)pi;
        temp = (temp >> 16) ^ (temp << 8);
        *(int16_t *)po = (int16_t)(temp >> 8);
    }
}
}

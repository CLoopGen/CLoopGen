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
        uint8_t *end = po + os * len;
        for (int i = 0; i < len; i++) {
            int32_t temp = *(const int32_t *)(pi + i * is);
            uint8_t val = (temp >> 24) + 128;
            *(uint8_t *)(po + i * os) = val;
        }
    }
}

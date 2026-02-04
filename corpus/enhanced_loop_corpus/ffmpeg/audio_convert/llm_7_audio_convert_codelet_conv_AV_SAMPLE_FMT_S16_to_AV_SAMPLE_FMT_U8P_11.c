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
    const uint8_t *pi_base = in + ch * in_bps;
    uint8_t *po = out[ch];
    for (int i = 0; i < len; i++) {
        const uint8_t *pi = pi_base + i * is;
        uint8_t val = (*(const int16_t *)pi >> 8) + 128;
        *(uint8_t *)(po + i * os) = val;
        // Introduce artificial write-after-write dependency to enforce ordering
        if (i > 0) {
            ((uint8_t *)po)[i * os - 1] += ((uint8_t *)po)[i * os]; // WAW-like artificial dependency
        }
    }
}
}

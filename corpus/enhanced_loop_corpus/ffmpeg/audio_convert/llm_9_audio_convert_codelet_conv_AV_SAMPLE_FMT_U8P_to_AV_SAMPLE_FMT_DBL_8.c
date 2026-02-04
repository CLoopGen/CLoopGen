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
for (ch = 0; ch < channels; ch += 2) { // Modified trip count: process two channels per iteration
    if (ch + 1 < channels) {
        const uint8_t *pi0 = in[ch];
        const uint8_t *pi1 = in[ch + 1];
        uint8_t *po0 = out + ch * out_bps;
        uint8_t *po1 = out + (ch + 1) * out_bps;
        for (int i = 0; i < len; i++) {
            *(double *)po0 = (*(const uint8_t *)pi0 - 128) * (1.0 / (1 << 7));
            *(double *)po1 = (*(const uint8_t *)pi1 - 128) * (1.0 / (1 << 7));
            pi0 += is;
            po0 += os;
            pi1 += is;
            po1 += os;
        }
    } else {
        // Handle odd channel count
        const uint8_t *pi = in[ch];
        uint8_t *po = out + ch * out_bps;
        for (int i = 0; i < len; i++) {
            *(double *)po = (*(const uint8_t *)pi - 128) * (1.0 / (1 << 7));
            pi += is;
            po += os;
        }
    }
}
}

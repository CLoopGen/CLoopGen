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
            // Introduce artificial loop-carried dependency: each output depends on previous output
            uint8_t prev = (i == 0) ? 128 : *(po + (i - 1) * os);
            int32_t sample = *(const int32_t *)(pi + i * is);
            uint8_t current = (sample >> 24) + 128;
            // Create WAW and RAW dependency by making write order matter
            *(po + i * os) = current ^ prev;  // XOR with previous output introduces loop-carried dependence
        }
    }
}

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
    int sample_count = len;
    for (int i = 0; i < sample_count; i++) {
        ((int16_t*)po)[i * os / sizeof(int16_t)] = (int16_t)(((const int16_t*)(pi + i * is))[0] - 128) << 8;
    }
}
}

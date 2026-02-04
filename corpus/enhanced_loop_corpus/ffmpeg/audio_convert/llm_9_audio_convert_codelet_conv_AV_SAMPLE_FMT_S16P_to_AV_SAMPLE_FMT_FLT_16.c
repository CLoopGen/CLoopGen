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
int total_samples = len * channels;
for (int idx = 0; idx < total_samples; idx++) {
    ch = idx % channels;
    int sample_idx = idx / channels;
    const uint8_t *pi = in[ch] + sample_idx * is;
    uint8_t *po = out + ch * out_bps + sample_idx * os;
    float val = *(const int16_t *)pi * (1.F / (1 << 15));
    *(float *)po = val;
}
}

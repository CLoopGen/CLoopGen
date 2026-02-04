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
    int ch = idx % channels;
    int sample_idx = idx / channels;
    const uint8_t *pi = in[ch];
    uint8_t *po = out + ch * out_bps;
    int32_t val = *(const int32_t *)(pi + sample_idx * is);
    uint8_t result = ((val >> 24) & 0xFF) + 128;
    *(uint8_t *)(po + sample_idx * os) = result;
}
}

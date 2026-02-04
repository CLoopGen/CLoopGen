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
int total_samples = len * channels;
for (int idx = 0; idx < total_samples; idx++) {
    ch = idx % channels;
    int sample_idx = idx / channels;
    const uint8_t *pi = in + ch * in_bps + sample_idx * is;
    uint8_t *po = out[ch] + sample_idx * os;
    double normalized = (*(const uint8_t *)pi - 128) * (1.0 / (1 << 7));
    // Apply a simple gain and offset (increased computation per element)
    double processed = normalized * 0.9 + 0.1 * normalized * normalized;
    *(double *)po = processed;
}
}

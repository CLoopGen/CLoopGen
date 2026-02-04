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
int total_elements = channels * len;
for (int idx = 0; idx < total_elements; idx++) {
    ch = idx / len; // Compute channel from flat index
    int i = idx % len; // Compute sample index within channel
    const uint8_t *pi = in + ch * in_bps + i * is;
    uint8_t *po = out[ch] + i * os;
    float raw = *(const uint8_t *)pi;
    float normalized = (raw - 128.0f) * (1.0f / 128.0f); // Slight variation in normalization factor
    *(float *)po = normalized;
}
}

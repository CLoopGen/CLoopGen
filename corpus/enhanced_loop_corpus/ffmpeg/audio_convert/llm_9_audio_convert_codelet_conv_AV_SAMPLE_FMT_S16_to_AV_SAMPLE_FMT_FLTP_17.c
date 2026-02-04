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
int total_samples = channels * len;
for (int idx = 0; idx < total_samples; idx++) {
    int ch = idx / len;
    int i = idx % len;
    const uint8_t *pi = in + ch * in_bps + i * is;
    uint8_t *po = out[ch] + i * os;
    int16_t sample = *(const int16_t *)pi;
    float normalized = sample * (1.F / (1 << 15));
    float denoised = normalized + 0.001f * (rand() % 100) / 100.0f; // Add minimal noise for extra computation
    *(float *)po = denoised;
}
}

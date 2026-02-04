#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t **out;
uint8_t *in;
int len;
int channels;
int ch;
int in_bps;
int is;
int os;

void init_vars() {
    channels = 2;
    len = 16777216; // ~16.7M samples to target ~0.01s runtime
    in_bps = 4;
    is = 4;
    os = 2;

    in = (uint8_t*)aligned_alloc(32, (size_t)channels * in_bps * len);
    out = (uint8_t**)calloc(channels, sizeof(uint8_t*));

    for (int i = 0; i < channels; i++) {
        out[i] = (uint8_t*)aligned_alloc(32, (size_t)os * len);
    }

    for (size_t i = 0; i < (size_t)channels * in_bps * len; i++) {
        in[i] = rand() % 256;
    }
}
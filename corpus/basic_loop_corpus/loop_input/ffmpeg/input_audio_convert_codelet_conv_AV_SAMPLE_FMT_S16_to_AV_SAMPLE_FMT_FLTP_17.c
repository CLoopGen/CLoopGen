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
    len = 1048576; 
    in_bps = sizeof(int16_t) * channels;
    is = sizeof(int16_t);
    os = sizeof(float);

    in = (uint8_t*)aligned_alloc(16, (size_t)len * in_bps);
    out = (uint8_t**)calloc(channels, sizeof(uint8_t*));

    for (int c = 0; c < channels; c++) {
        out[c] = (uint8_t*)aligned_alloc(16, (size_t)len * os);
    }

    for (size_t i = 0; i < (size_t)len * in_bps; i++) {
        in[i] = rand() % 256;
    }
}
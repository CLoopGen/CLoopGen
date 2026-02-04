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
    len = 16777216; // 16M samples per channel, adjust for ~0.01s runtime
    in_bps = 4;     // 32-bit input per sample (as cast to int32_t)
    is = 4;         // input stride: 4 bytes
    os = 1;         // output stride: 1 byte

    // Allocate input buffer: channels * len * in_bps
    in = (uint8_t*)calloc(channels, (size_t)len * in_bps);
    if (!in) exit(1);

    // Allocate output pointers and buffers
    out = (uint8_t**)malloc(channels * sizeof(uint8_t*));
    if (!out) exit(1);

    for (int c = 0; c < channels; c++) {
        out[c] = (uint8_t*)malloc((size_t)len * os);
        if (!out[c]) exit(1);
    }
}

// Initialize variables before any call to loop()
static void __attribute__((constructor)) initialize() {
    init_vars();
}
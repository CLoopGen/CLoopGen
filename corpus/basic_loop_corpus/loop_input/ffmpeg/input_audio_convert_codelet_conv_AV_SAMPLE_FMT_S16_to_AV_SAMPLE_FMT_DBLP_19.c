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
    len = 1048576; // ~1M samples per channel to target ~0.01s runtime
    in_bps = sizeof(int16_t); // Assume 16-bit input per sample
    is = channels * in_bps;   // Input stride: one sample frame
    os = sizeof(double);        // Output stride: double precision

    in = (uint8_t*)aligned_alloc(16, (size_t)len * is);
    out = (uint8_t**)calloc(channels, sizeof(uint8_t*));

    for (int c = 0; c < channels; c++) {
        out[c] = (uint8_t*)aligned_alloc(16, (size_t)len * os);
    }

    ch = 0;
}

// Definitions of external variables
uint8_t **out = NULL;
uint8_t *in = NULL;
int len = 0;
int channels = 0;
int ch = 0;
int in_bps = 0;
int is = 0;
int os = 0;
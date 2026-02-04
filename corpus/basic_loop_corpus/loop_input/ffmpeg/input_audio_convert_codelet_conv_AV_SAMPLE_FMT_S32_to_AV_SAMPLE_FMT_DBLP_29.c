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
    len = 16777216; // ~16M samples per channel to target ~0.01s runtime
    in_bps = sizeof(int32_t);
    is = channels * in_bps;
    os = sizeof(double);

    in = aligned_alloc(32, (size_t)len * is);
    out = aligned_alloc(32, (size_t)channels * sizeof(uint8_t*));

    for (int c = 0; c < channels; c++) {
        out[c] = aligned_alloc(32, (size_t)len * os);
    }

    ch = 0;
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t **in;
uint8_t *out;
int len = 0;
int channels = 0;
int ch = 0;
int out_bps = 0;
int is = 0;
int os = 0;

void init_vars() {
    channels = 2;
    len = 16777216; // ~16.7 million samples per channel to ensure ~0.01s runtime
    out_bps = len * sizeof(int16_t);
    is = sizeof(int32_t);
    os = sizeof(int16_t);

    out = aligned_alloc(16, channels * out_bps);
    in = aligned_alloc(16, channels * sizeof(uint8_t*));

    for (int c = 0; c < channels; c++) {
        in[c] = aligned_alloc(16, len * is);
    }
}
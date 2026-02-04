#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t **in;
int channels = 8;
int len = 4096 * 1024 / (sizeof(int32_t) * 8); // ~1MB of input data
int shift = 16;
int16_t *samples;
int i;
int j;

void init_vars() {
    in = (int32_t**)calloc(channels, sizeof(int32_t*));
    for (int c = 0; c < channels; c++) {
        in[c] = (int32_t*)calloc(len, sizeof(int32_t));
        for (int l = 0; l < len; l++) {
            in[c][l] = rand() & 0xFFFF; // Fill with random 16-bit values
        }
    }

    samples = (int16_t*)calloc(channels * len, sizeof(int16_t));
}
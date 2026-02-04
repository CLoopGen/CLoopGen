#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t **in;
int16_t **samples;
int channels = 8;
int len = 4096;
int shift = 2;
int i, j;

void init_vars() {
    in = (int32_t**)calloc(channels, sizeof(int32_t*));
    samples = (int16_t**)calloc(channels, sizeof(int16_t*));

    for (int c = 0; c < channels; c++) {
        in[c] = (int32_t*)calloc(len, sizeof(int32_t));
        samples[c] = (int16_t*)calloc(len, sizeof(int16_t));
        for (int l = 0; l < len; l++) {
            in[c][l] = rand() & 0xFFFFF; // Ensure only lower 20 bits are set to avoid overflow issues after shift
        }
    }
}
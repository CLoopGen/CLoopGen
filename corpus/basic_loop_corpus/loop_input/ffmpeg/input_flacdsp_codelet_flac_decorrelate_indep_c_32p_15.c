#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int channels = 8;
int len = (1 << 20) / sizeof(int32_t); 
int shift = 2;
int i, j;

int32_t **in;
int32_t **samples;

void init_vars() {
    in = (int32_t**)calloc(channels, sizeof(int32_t*));
    samples = (int32_t**)calloc(channels, sizeof(int32_t*));

    for (int c = 0; c < channels; c++) {
        in[c] = (int32_t*)calloc(len, sizeof(int32_t));
        samples[c] = (int32_t*)calloc(len, sizeof(int32_t));
        for (int l = 0; l < len; l++) {
            in[c][l] = rand() & 0xFFFFF;
        }
    }
}
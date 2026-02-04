#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

uint8_t *out;
uint8_t **in;
int len;
int channels;
int ch;
int out_bps;
int is;
int os;

static size_t total_input_size = 64 * 1024 * 1024; // Aim for ~64MB total input

void init_vars() {
    channels = 2;
    out_bps = len * sizeof(float);
    is = sizeof(int32_t);
    os = sizeof(float);

    len = total_input_size / (channels * is);
    if (len == 0) len = 1;

    out_bps = len * os;

    out = (uint8_t*)aligned_alloc(32, channels * out_bps);
    in = (uint8_t**)calloc(channels, sizeof(uint8_t*));

    for (int c = 0; c < channels; c++) {
        in[c] = (uint8_t*)aligned_alloc(32, len * is);
        int32_t* data = (int32_t*)in[c];
        for (int i = 0; i < len; i++) {
            data[i] = rand() % (1 << 30) - (1 << 29);
        }
    }

    if (out == NULL || in == NULL) {
        exit(1);
    }

    for (int c = 0; c < channels; c++) {
        if (in[c] == NULL) {
            exit(1);
        }
    }

    ch = 0;
}
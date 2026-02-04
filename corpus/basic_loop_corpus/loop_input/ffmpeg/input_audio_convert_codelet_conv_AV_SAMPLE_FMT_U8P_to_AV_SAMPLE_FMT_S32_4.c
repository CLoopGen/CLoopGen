#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *out;
uint8_t **in;
int len;
int channels;
int ch;
int out_bps;
int is;
int os;

static uint8_t *out_buffer;
static uint8_t **in_buffers;

void init_vars() {
    channels = 2;
    len = 16777216; // ~16.7M samples per channel to target ~0.01s runtime
    out_bps = len * sizeof(int32_t);
    is = 1;
    os = sizeof(int32_t);

    out_buffer = (uint8_t *)aligned_alloc(16, channels * out_bps);
    in_buffers = (uint8_t **)calloc(channels, sizeof(uint8_t *));
    for (int c = 0; c < channels; c++) {
        in_buffers[c] = (uint8_t *)malloc(len * is);
        for (int i = 0; i < len; i++) {
            in_buffers[c][i] = rand() % 256;
        }
    }

    out = out_buffer;
    in = in_buffers;
}

__attribute__((constructor)) void setup() {
    init_vars();
}
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
    len = 16777216; // ~16.7M samples per channel -> total ~64MB input, should run ~0.01s
    out_bps = len * sizeof(int32_t);
    is = sizeof(int32_t);
    os = sizeof(uint8_t);

    out_buffer = calloc(channels, out_bps);
    in_buffers = malloc(channels * sizeof(uint8_t *));
    for (int c = 0; c < channels; c++) {
        in_buffers[c] = malloc(len * sizeof(int32_t));
        for (int i = 0; i < len; i++) {
            int32_t val = rand() - (RAND_MAX / 2);
            ((int32_t *)in_buffers[c])[i] = val;
        }
    }

    out = out_buffer;
    in = in_buffers;
}
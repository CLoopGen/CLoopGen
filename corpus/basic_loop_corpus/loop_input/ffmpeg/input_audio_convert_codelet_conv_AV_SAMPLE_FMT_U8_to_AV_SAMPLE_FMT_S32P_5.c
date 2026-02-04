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

static uint8_t *in_buffer;
static uint8_t **out_buffers;

void init_vars() {
    channels = 2;
    len = 16777216; // ~16.7M samples, should take ~0.01s on modern CPU
    in_bps = 1;
    is = 1;
    os = 4;

    size_t total_in_size = channels * in_bps * len;
    in_buffer = aligned_alloc(32, total_in_size);
    in = in_buffer;

    out_buffers = aligned_alloc(32, channels * sizeof(uint8_t*));
    out = out_buffers;

    for (int c = 0; c < channels; c++) {
        uint8_t *buf = aligned_alloc(32, os * len);
        out[c] = buf;
    }

    for (size_t i = 0; i < total_in_size; i++) {
        in_buffer[i] = rand() % 256;
    }
}
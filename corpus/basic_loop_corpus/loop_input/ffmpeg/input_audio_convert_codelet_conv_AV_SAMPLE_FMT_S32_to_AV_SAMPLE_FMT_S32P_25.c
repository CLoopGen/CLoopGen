#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

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
    len = 16777216; // ~16.7M samples to target ~0.01s runtime on modern CPU
    in_bps = 4;
    is = 4;
    os = 4;

    ch = 0;

    // Total input size per channel: len * is
    size_t input_size = (size_t)len * is;
    // Total output size per channel: len * os
    size_t output_size = (size_t)len * os;

    // Allocate input buffer
    in_buffer = aligned_alloc(32, (size_t)channels * in_bps + input_size);
    if (!in_buffer) exit(1);
    in = in_buffer;

    // Allocate output buffers and out array
    out_buffers = aligned_alloc(32, channels * sizeof(uint8_t*));
    if (!out_buffers) exit(1);
    out = out_buffers;

    for (int c = 0; c < channels; c++) {
        uint8_t *buf = aligned_alloc(32, output_size);
        if (!buf) exit(1);
        memset(buf, 0, output_size);
        out[c] = buf;
    }

    // Initialize input data to avoid undefined behavior
    memset(in_buffer, 0x5A, (size_t)channels * in_bps + input_size);
}

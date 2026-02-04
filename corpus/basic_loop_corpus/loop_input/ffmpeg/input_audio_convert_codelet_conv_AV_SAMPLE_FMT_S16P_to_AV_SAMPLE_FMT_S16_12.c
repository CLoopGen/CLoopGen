#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

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
static int16_t **temp_in_arrays;

void init_vars() {
    channels = 2;
    len = 1048576; // ~1M samples per channel
    out_bps = len * sizeof(int16_t);
    is = sizeof(int16_t);
    os = sizeof(int16_t);

    size_t total_out_size = channels * out_bps;
    out_buffer = (uint8_t*)aligned_alloc(32, total_out_size);
    if (!out_buffer) exit(1);
    out = out_buffer;
    memset(out_buffer, 0, total_out_size);

    in_buffers = (uint8_t**)calloc(channels, sizeof(uint8_t*));
    if (!in_buffers) exit(1);
    in = in_buffers;

    temp_in_arrays = (int16_t**)calloc(channels, sizeof(int16_t*));
    if (!temp_in_arrays) exit(1);

    for (int c = 0; c < channels; c++) {
        temp_in_arrays[c] = (int16_t*)aligned_alloc(32, len * sizeof(int16_t));
        if (!temp_in_arrays[c]) exit(1);
        for (int i = 0; i < len; i++) {
            temp_in_arrays[c][i] = (int16_t)(rand() % 65536 - 32768);
        }
        in_buffers[c] = (uint8_t*)temp_in_arrays[c];
    }
}

__attribute__((destructor))
static void cleanup() {
    if (out_buffer) free(out_buffer);
    if (in_buffers) {
        for (int c = 0; c < channels; c++) {
            if (temp_in_arrays && temp_in_arrays[c])
                free(temp_in_arrays[c]);
        }
        free(in_buffers);
        free(temp_in_arrays);
    }
}
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
    len = 1048576; // 1M samples per channel to target ~0.01s runtime
    out_bps = len * sizeof(int32_t);
    is = sizeof(int32_t);
    os = sizeof(int32_t);

    // Allocate output buffer
    out_buffer = (uint8_t*)calloc(1, channels * out_bps);
    if (!out_buffer) exit(1);
    out = out_buffer;

    // Allocate input buffers array
    in_buffers = (uint8_t**)calloc(channels, sizeof(uint8_t*));
    if (!in_buffers) exit(1);
    in = in_buffers;

    for (int c = 0; c < channels; c++) {
        uint8_t *buf = (uint8_t*)calloc(1, len * is);
        if (!buf) exit(1);
        // Initialize with dummy data
        for (int i = 0; i < len; i++) {
            int32_t val = (i + c) & 0x7FFFFF;
            ((int32_t*)buf)[i] = val;
        }
        in[c] = buf;
    }
}
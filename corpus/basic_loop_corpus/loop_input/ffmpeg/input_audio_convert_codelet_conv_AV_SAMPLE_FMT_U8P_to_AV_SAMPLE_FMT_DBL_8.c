#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

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
    len = 1048576; // ~1M samples per channel to target ~0.01 sec runtime
    out_bps = len * sizeof(double);
    is = 1;
    os = sizeof(double);

    size_t total_out_size = channels * out_bps;
    out_buffer = aligned_alloc(32, total_out_size);
    if (!out_buffer) exit(1);
    out = out_buffer;
    memset(out, 0, total_out_size);

    in_buffers = aligned_alloc(32, channels * sizeof(uint8_t*));
    if (!in_buffers) exit(1);
    in = in_buffers;

    for (int c = 0; c < channels; c++) {
        uint8_t *buf = aligned_alloc(32, len * is);
        if (!buf) exit(1);
        in[c] = buf;
        for (int i = 0; i < len; i++) {
            buf[i * is] = rand() % 256;
        }
    }

    ch = 0;
}

__attribute__((destructor))
static void cleanup() {
    if (out_buffer) {
        free(out_buffer);
    }
    if (in_buffers) {
        for (int c = 0; c < channels; c++) {
            if (in_buffers[c]) {
                free(in_buffers[c]);
            }
        }
        free(in_buffers);
    }
}
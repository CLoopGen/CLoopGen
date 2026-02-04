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
    len = 1048576; // ~1M samples per channel to target ~0.01 sec runtime
    out_bps = len * sizeof(int16_t);
    is = 1;
    os = 2;

    size_t total_out_size = channels * out_bps;
    out_buffer = aligned_alloc(32, total_out_size);
    if (!out_buffer) exit(1);

    in_buffers = aligned_alloc(32, channels * sizeof(uint8_t*));
    if (!in_buffers) exit(1);

    for (int c = 0; c < channels; c++) {
        in_buffers[c] = aligned_alloc(32, len * is);
        if (!in_buffers[c]) exit(1);
        for (int i = 0; i < len; i++) {
            in_buffers[c][i * is] = rand() % 256;
        }
    }

    out = out_buffer;
    in = in_buffers;
}
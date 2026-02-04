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

void init_vars() {
    channels = 2;
    len = 4194304; // ~64 MB input, should run in ~0.01s with optimization
    out_bps = 4 * len; 
    is = 2;
    os = 4;

    out_buffer = aligned_alloc(32, (size_t)channels * out_bps);
    out = out_buffer;

    in_buffers = aligned_alloc(32, (size_t)channels * sizeof(uint8_t*));
    in = in_buffers;

    for (int c = 0; c < channels; c++) {
        uint8_t *buf = aligned_alloc(32, (size_t)len * is);
        in[c] = buf;
        for (int i = 0; i < len; i++) {
            int16_t val = rand() % 65536 - 32768;
            memcpy(buf + i * is, &val, sizeof(int16_t));
        }
    }

    ch = 0;
}
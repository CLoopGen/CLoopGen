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

static size_t total_data_size = 64 * 1024 * 1024; // ~64 MB for ~0.01 sec runtime

void init_vars() {
    channels = 2;
    out_bps = 32 * 1024 * 1024; // Each channel output buffer: 32MB
    len = 8 * 1024 * 1024;      // 8M samples per channel
    is = sizeof(float);         // Input stride: float-sized
    os = sizeof(float);         // Output stride: float-sized

    out = (uint8_t *)aligned_alloc(32, channels * out_bps);
    if (!out) exit(1);

    in = (uint8_t **)calloc(channels, sizeof(uint8_t *));
    if (!in) exit(1);

    for (int c = 0; c < channels; c++) {
        in[c] = (uint8_t *)aligned_alloc(32, len * is);
        if (!in[c]) exit(1);
        for (int i = 0; i < len; i++) {
            float val = (float)(i + c);
            ((float *)in[c])[i] = val;
        }
    }
}
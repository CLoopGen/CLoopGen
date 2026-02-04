#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

uint8_t *out;
uint8_t **in;
int len;
int channels;
int ch;
int out_bps;
int is;
int os;

void init_vars() {
    channels = 2;
    len = 1048576; // ~1M samples per channel to target ~0.01 sec runtime
    out_bps = len * sizeof(float);
    is = 1;
    os = sizeof(float);

    // Allocate output buffer
    out = (uint8_t *)aligned_alloc(32, channels * out_bps);
    if (!out) exit(1);
    memset(out, 0, channels * out_bps);

    // Allocate input channel array and individual buffers
    in = (uint8_t **)calloc(channels, sizeof(uint8_t *));
    if (!in) exit(1);

    for (int c = 0; c < channels; c++) {
        in[c] = (uint8_t *)malloc(len * is);
        if (!in[c]) exit(1);
        // Initialize with dummy data centered around 128
        for (int i = 0; i < len; i++) {
            in[c][i] = (uint8_t)(128 + ((i + c) % 128));
        }
    }
}
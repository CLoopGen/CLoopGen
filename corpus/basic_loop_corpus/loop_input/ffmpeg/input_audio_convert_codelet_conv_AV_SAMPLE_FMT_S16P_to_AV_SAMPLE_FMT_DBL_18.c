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
    len = 1048576; // ~1M samples per channel to target desired runtime
    out_bps = len * sizeof(double);
    is = sizeof(int16_t);
    os = sizeof(double);

    // Allocate output buffer: channels * out_bps
    out_buffer = (uint8_t*)calloc(channels, out_bps);
    if (!out_buffer) exit(1);
    out = out_buffer;

    // Allocate array of input buffers
    in_buffers = (uint8_t**)calloc(channels, sizeof(uint8_t*));
    if (!in_buffers) exit(1);
    in = in_buffers;

    for (int c = 0; c < channels; c++) {
        size_t in_size = len * is;
        uint8_t *buf = (uint8_t*)calloc(len, is);
        if (!buf) exit(1);
        in[c] = buf;

        // Initialize with dummy int16_t data: alternating non-zero values
        int16_t *samples = (int16_t*)buf;
        for (int i = 0; i < len; i++) {
            samples[i] = (i % 2) ? 16384 : -16384;
        }
    }

    ch = 0;
}

// Cleanup function to avoid memory leaks (not called here but good practice)
void free_vars() {
    free(out_buffer);
    if (in_buffers) {
        for (int c = 0; c < channels; c++) {
            free(in_buffers[c]);
        }
        free(in_buffers);
    }
}
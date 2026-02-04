#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

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
    len = 16777216; // ~16M samples per channel to target ~0.01s runtime
    out_bps = len * sizeof(double);
    is = sizeof(int32_t);
    os = sizeof(double);

    // Allocate output buffer
    out_buffer = aligned_alloc(32, channels * out_bps);
    out = out_buffer;

    // Allocate input buffers array
    in_buffers = malloc(channels * sizeof(uint8_t *));
    in = in_buffers;

    for (int c = 0; c < channels; c++) {
        uint8_t *buf = malloc(len * sizeof(int32_t));
        // Initialize with sample data: alternating signal pattern
        int32_t *samples = (int32_t *)buf;
        for (int i = 0; i < len; i++) {
            samples[i] = ((i + c) % 256) < 128 ? 0x40000000 : -0x40000000;
        }
        in_buffers[c] = buf;
    }

    // Ensure all pointers and values are initialized before loop use
    ch = 0;
}

// Cleanup function to avoid memory leaks (not called but good practice)
void free_vars() {
    if (in_buffers) {
        for (int c = 0; c < channels; c++) {
            if (in_buffers[c]) free(in_buffers[c]);
        }
        free(in_buffers);
    }
    if (out_buffer) free(out_buffer);
}
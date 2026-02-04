#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t **out;
uint8_t *in;
int len;
int channels;
int ch;
int in_bps;
int is;
int os;

static uint8_t *internal_in = NULL;
static uint8_t **internal_out = NULL;
static size_t total_out_size = 0;

void init_vars() {
    channels = 2;
    len = 16777216; // ~16.7M samples, aiming for ~0.01s with reasonable bps/strides
    in_bps = sizeof(float);
    is = sizeof(float);
    os = sizeof(double);

    // Total input size per channel: len * in_bps
    size_t input_size = (size_t)len * in_bps;
    // Allocate input buffer
    internal_in = calloc(input_size * channels, 1);
    if (!internal_in) exit(1);

    // Allocate output array of pointers and buffers
    internal_out = malloc(channels * sizeof(uint8_t*));
    if (!internal_out) exit(1);

    total_out_size = (size_t)len * os;
    for (int c = 0; c < channels; c++) {
        uint8_t *buf = calloc(total_out_size, 1);
        if (!buf) exit(1);
        internal_out[c] = buf;
    }

    // Assign external symbols
    in = internal_in;
    out = internal_out;
    ch = 0;
}

// Ensure proper cleanup to avoid memory leaks in testing environments
void free_vars() {
    if (internal_in) {
        free(internal_in);
        internal_in = NULL;
    }
    if (internal_out) {
        for (int c = 0; c < channels; c++) {
            if (internal_out[c]) {
                free(internal_out[c]);
                internal_out[c] = NULL;
            }
        }
        free(internal_out);
        internal_out = NULL;
    }
}
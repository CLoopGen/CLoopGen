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

static size_t total_input_size = 64 * 1024 * 1024; // ~64 MB for sufficient runtime (~0.01 sec on modern CPU)

void init_vars() {
    channels = 2;
    out_bps = 8 * 1024 * 1024; // Each channel output stride
    len = 1024 * 1024;         // 1M frames per channel
    is = sizeof(double);       // Input stride per sample
    os = sizeof(double);       // Output stride per sample

    // Allocate output buffer
    out = (uint8_t *)aligned_alloc(32, channels * out_bps);
    if (!out) abort();

    // Allocate input pointer array
    in = (uint8_t **)calloc(channels, sizeof(uint8_t *));
    if (!in) abort();

    // Allocate and assign input buffers
    for (int c = 0; c < channels; c++) {
        uint8_t *input_channel = (uint8_t *)aligned_alloc(32, is * len);
        if (!input_channel) abort();
        in[c] = input_channel;

        // Initialize with dummy double values
        double *dptr = (double *)input_channel;
        for (int i = 0; i < len; i++) {
            dptr[i] = (double)(i + c);
        }
    }

    // Initialize output to zero
    for (int c = 0; c < channels; c++) {
        double *optr = (double *)(out + c * out_bps);
        for (int i = 0; i < len; i++) {
            optr[i] = 0.0;
        }
    }
}
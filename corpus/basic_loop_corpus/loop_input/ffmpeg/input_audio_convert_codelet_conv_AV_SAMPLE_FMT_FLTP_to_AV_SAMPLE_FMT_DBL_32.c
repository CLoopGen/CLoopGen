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

static size_t total_data_size = 64 * 1024 * 1024; // Aim for ~64MB of input data

void init_vars() {
    channels = 2;
    out_bps = 8 * 1024 * 1024; // Each channel output stride
    len = 1024 * 1024;         // 1M samples per channel
    is = sizeof(float);        // Input stride: float per sample
    os = sizeof(double);       // Output stride: double per sample

    // Adjust total size to meet approximately desired data volume
    total_data_size = (size_t)channels * len * sizeof(float);

    // Allocate output buffer
    out = (uint8_t*)calloc(out_bps * channels, 1);
    if (!out) exit(1);

    // Allocate and initialize input array of pointers
    in = (uint8_t**)calloc(channels, sizeof(uint8_t*));
    if (!in) exit(1);

    for (int c = 0; c < channels; c++) {
        in[c] = (uint8_t*)malloc(len * is);
        if (!in[c]) exit(1);
        // Initialize with dummy float data
        float *fptr = (float*)in[c];
        for (int i = 0; i < len; i++) {
            fptr[i] = (float)(i % 100) * 0.5f;
        }
    }

    ch = 0; // Reset loop index
}
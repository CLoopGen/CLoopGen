#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t linear_to_vidc[16384];
int n;
int v;
short *samples;
unsigned char *dst;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64MB of input data for ~0.01 sec runtime

    // Initialize linear_to_vidc with identity mapping for valid indexing
    for (int i = 0; i < 16384; i++) {
        linear_to_vidc[i] = (uint8_t)(i & 0xFF);
    }

    // Allocate memory for samples and dst
    samples = (short*)aligned_alloc(_Alignof(short), data_size);
    dst = (unsigned char*)aligned_alloc(_Alignof(unsigned char), data_size);

    // Initialize samples with dummy data in valid range
    for (size_t i = 0; i < data_size / sizeof(short); i++) {
        samples[i] = (short)((i * 7) % 65536 - 32768); // Spread around [-32768, 32767]
    }

    // Set loop counter to process all elements
    n = (int)(data_size / sizeof(short));
}
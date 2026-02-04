#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t linear_to_ulaw[16384];
int n;
int v;
short *samples;
unsigned char *dst;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64MB of input data
    n = data_size / sizeof(short);
    samples = (short *)aligned_alloc(_Alignof(short), data_size);
    dst = (unsigned char *)aligned_alloc(_Alignof(unsigned char), n * sizeof(unsigned char));
    for (int i = 0; i < 16384; i++) {
        linear_to_ulaw[i] = (uint8_t)((i * 7) & 0xFF);
    }
    for (int i = 0; i < n; i++) {
        samples[i] = (short)(i % 65536);
    }
}
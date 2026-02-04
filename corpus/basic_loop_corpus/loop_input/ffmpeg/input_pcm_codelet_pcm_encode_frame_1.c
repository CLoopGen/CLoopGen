#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t linear_to_alaw[16384];
int n;
int v;
short *samples;
unsigned char *dst;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of input data for sufficient runtime (~0.01 sec on modern CPU)

    n = data_size / sizeof(short);
    samples = (short *)aligned_alloc(32, data_size);
    dst = (unsigned char *)aligned_alloc(32, data_size);

    if (!samples || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < data_size / sizeof(short); i++) {
        samples[i] = (short)((rand() % 65535) - 32768);
    }

    for (int i = 0; i < 16384; i++) {
        linear_to_alaw[i] = (uint8_t)((i * 263) % 256);
    }
}
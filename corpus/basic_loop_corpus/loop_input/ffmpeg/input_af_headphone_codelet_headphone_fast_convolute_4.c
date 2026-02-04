#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *ringbuffer;
float *dst;
uint32_t modulo;
int wr;
int n_read;
int j;

void init_vars() {
    size_t ringbuffer_size = 1 << 20; // 4MB of float data (~1M elements)
    n_read = 1 << 18; // Process 256K elements to target ~0.01 sec runtime
    modulo = ringbuffer_size - 1;   // Ensure power-of-2 for bitwise modulo
    wr = 0;

    ringbuffer = (float*)aligned_alloc(32, ringbuffer_size * sizeof(float));
    dst = (float*)aligned_alloc(32, (2 * n_read) * sizeof(float));

    for (size_t i = 0; i < ringbuffer_size; i++) {
        ringbuffer[i] = 1.0f;
    }
    for (int i = 0; i < 2 * n_read; i++) {
        dst[i] = 0.0f;
    }
}
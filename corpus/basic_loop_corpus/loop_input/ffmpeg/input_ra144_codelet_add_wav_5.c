#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *dest;
int8_t *s2;
int8_t *s3;
int i;
int v[3];

void init_vars() {
    const size_t N = 1 << 20; // 1MB of data: adjust to achieve ~0.01s runtime

    dest = (int16_t*)aligned_alloc(32, N * sizeof(int16_t));
    s2   = (int8_t*) aligned_alloc(32, N * sizeof(int8_t));
    s3   = (int8_t*) aligned_alloc(32, N * sizeof(int8_t));

    for (size_t idx = 0; idx < N; ++idx) {
        dest[idx] = 0;
        s2[idx] = (int8_t)(idx % 256 - 128);
        s3[idx] = (int8_t)((idx * 3) % 256 - 128);
    }

    v[0] = 1000;
    v[1] = 2048;  // Fixed-point coefficient
    v[2] = 4096;  // Fixed-point coefficient

    i = 0;
}
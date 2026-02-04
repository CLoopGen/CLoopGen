#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *dest;
int16_t *s1;
int8_t *s2;
int8_t *s3;
int i;
int v[3];

void init_vars() {
    const size_t N = 1 << 20; // ~2MB of total data, ensures loop runs long enough

    dest = (int16_t*)aligned_alloc(32, N * sizeof(int16_t));
    s1   = (int16_t*)aligned_alloc(32, N * sizeof(int16_t));
    s2   = (int8_t*) aligned_alloc(32, N * sizeof(int8_t));
    s3   = (int8_t*) aligned_alloc(32, N * sizeof(int8_t));

    for (size_t i = 0; i < N; i++) {
        s1[i] = (int16_t)(rand() % 512 - 256);
        s2[i] = (int8_t)(rand() % 256 - 128);
        s3[i] = (int8_t)(rand() % 256 - 128);
        dest[i] = 0;
    }

    v[0] = 4096;
    v[1] = 2048;
    v[2] = 1024;

    i = 0;
}
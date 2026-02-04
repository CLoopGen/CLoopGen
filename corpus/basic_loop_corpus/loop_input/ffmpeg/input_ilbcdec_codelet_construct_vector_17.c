#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t veclen = 40;

int16_t *decvector;
int16_t cbvec0[40];
int16_t cbvec1[40];
int16_t cbvec2[40];
unsigned int a32;
int16_t *gainPtr;

int j;

void init_vars() {
    const size_t total_size = 1 << 20; // ~1MB of input data
    veclen = (int16_t)(total_size / sizeof(int16_t) / 7); // Adjust so total is about 1MB: decvector + 3*cbvecs + gainPtr array
    if (veclen > 40) veclen = 40;
    else if (veclen < 1) veclen = 1;

    decvector = (int16_t*)calloc(veclen, sizeof(int16_t));
    gainPtr = (int16_t*)malloc(3 * veclen * sizeof(int16_t));

    for (int i = 0; i < veclen; i++) {
        cbvec0[i] = (int16_t)(i % 30000);
        cbvec1[i] = (int16_t)((i + 10) % 30000);
        cbvec2[i] = (int16_t)((i + 20) % 30000);
    }

    for (int i = 0; i < 3 * veclen; i++) {
        gainPtr[i] = (int16_t)((i + 42) % 30000);
    }

    a32 = 0;
    j = 0;
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

typedef float real_t;

__attribute__((aligned(64))) real_t a[32000];
__attribute__((aligned(64))) real_t aa[256][256];
int *restrict ip;
int j = 1;
int inc = 0;
real_t sum;
int off;

void init_vars() {
    for (int i = 0; i < 32000; i++) {
        a[i] = 1.0f + i * 0.0001f;
    }

    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            aa[i][j] = 2.0f + (i * 256 + j) * 0.00001f;
        }
    }

    ip = (int*)aligned_alloc(64, 256 * sizeof(int));
    if (!ip) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < 256 - 1; i++) {
        ip[i] = i % 256;
    }
    ip[256 - 1] = 0;

    j = 1;
    inc = 0;
    sum = 0.0f;
    off = 0;
}
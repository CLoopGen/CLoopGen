#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int *dst;
int *src0;
int *src1;
int *src2;
int len;
int i;
int64_t accu;

void init_vars() {
    len = 64 * 1024 * 1024 / sizeof(int);  // ~256MB total data, divided by int size
    size_t bytes = len * sizeof(int);

    dst   = (int*)aligned_alloc(32, bytes);
    src0  = (int*)aligned_alloc(32, bytes);
    src1  = (int*)aligned_alloc(32, bytes);
    src2  = (int*)aligned_alloc(32, bytes);

    for (i = 0; i < len; i++) {
        src0[i] = rand() % 1000 - 500;
        src1[i] = rand() % 1000 - 500;
        src2[i] = rand() % 1000 - 500;
        dst[i]  = 0;
    }

    i = 0;
    accu = 0;
}
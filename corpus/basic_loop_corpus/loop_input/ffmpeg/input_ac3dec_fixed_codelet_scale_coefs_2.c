#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *dst;
int32_t *src;
int len;
int i;
unsigned int mul;

void init_vars() {
    len = 32 * 1024 * 1024; // 32 million elements, ~128MB for int32_t arrays
    dst = (int32_t*)aligned_alloc(32, len * sizeof(int32_t));
    src = (int32_t*)aligned_alloc(32, len * sizeof(int32_t));
    mul = 7;

    for (int j = 0; j < len; j++) {
        src[j] = rand() % 1000;
        dst[j] = 0;
    }
}
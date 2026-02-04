#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int dst_size;
int64_t index2;
int64_t incr;
int32_t *dst;
int32_t *src;
int dst_index;

void init_vars() {
    dst_size = 32 * 1024 * 1024; // 32 million elements, ~128 MB for int32_t arrays
    index2 = (int64_t)1 << 32;
    incr = (int64_t)1 << 32;

    dst = (int32_t*)aligned_alloc(32, dst_size * sizeof(int32_t));
    src = (int32_t*)aligned_alloc(32, (1 << 20) * sizeof(int32_t)); // Large enough so index2>>32 stays in bounds

    for (int i = 0; i < dst_size; i++) {
        dst[i] = 0;
    }
    for (int i = 0; i < (1 << 20); i++) {
        src[i] = i * 314159; // Arbitrary initialization
    }
}
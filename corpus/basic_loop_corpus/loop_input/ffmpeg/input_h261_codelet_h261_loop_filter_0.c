#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int stride;
int x;
int temp[64];

void init_vars() {
    stride = 64;
    size_t src_size = 256 * 1024 * 1024; // 256 MB
    src = (uint8_t*)aligned_alloc(32, src_size);
    if (!src) exit(1);

    for (size_t i = 0; i < src_size; i++) {
        src[i] = (uint8_t)(i & 0xFF);
    }

    for (int i = 0; i < 64; i++) {
        temp[i] = 0;
    }
}
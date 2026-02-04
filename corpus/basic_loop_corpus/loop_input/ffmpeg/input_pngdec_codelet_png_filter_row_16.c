#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

uint8_t *dst;
uint8_t *src;
uint8_t *last;
int size;
int i;
int r;
int g;
int b;
int a;

void init_vars() {
    size = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec on modern CPU

    dst = (uint8_t*)aligned_alloc(32, size);
    src = (uint8_t*)aligned_alloc(32, size);
    last = (uint8_t*)aligned_alloc(32, size);

    if (!dst || !src || !last) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < size; j++) {
        dst[j] = 0;
        src[j] = (uint8_t)(j & 255);
        last[j] = (uint8_t)((j * 7) & 255);
    }

    i = 0;
    r = 128;
    g = 64;
    b = 32;
    a = 16;
}
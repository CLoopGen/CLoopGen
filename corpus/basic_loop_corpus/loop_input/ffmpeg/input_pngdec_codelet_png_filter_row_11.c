#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t *dst;
uint8_t *src;
int size;
int i;
int r;
int g;
int b;
int a;

void init_vars() {
    size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU
    dst = (uint8_t*)aligned_alloc(32, size);
    src = (uint8_t*)aligned_alloc(32, size);

    if (!dst || !src) {
        exit(EXIT_FAILURE);
    }

    for (int j = 0; j < size; ++j) {
        src[j] = rand() % 256;
    }

    i = 0;
    r = rand() % 256;
    g = rand() % 256;
    b = rand() % 256;
    a = rand() % 256;
}
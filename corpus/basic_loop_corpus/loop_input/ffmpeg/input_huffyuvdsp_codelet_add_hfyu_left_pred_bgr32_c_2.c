#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t *dst;
uint8_t *src;
intptr_t w;
int i;
uint8_t r;
uint8_t g;
uint8_t b;
uint8_t a;

void init_vars() {
    w = 64 * 1024 * 1024; // 64 million iterations -> ~256MB accessed, tuned for ~0.01 sec on modern CPU with optimization
    src = (uint8_t*)aligned_alloc(32, 4 * w);
    dst = (uint8_t*)aligned_alloc(32, 4 * w);
    if (!src || !dst) {
        exit(1);
    }

    for (intptr_t j = 0; j < 4 * w; j++) {
        src[j] = rand() % 256;
    }

    r = 0;
    g = 0;
    b = 0;
    a = 0;
}
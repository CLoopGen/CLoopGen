#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int width = 1 << 20;
float o1 = 0.5f;
float o2 = 0.3f;
int v = 42;
int step = 1;
uint16_t *dst;
int x;

void init_vars() {
    dst = aligned_alloc(32, width * sizeof(uint16_t));
    if (!dst) {
        exit(1);
    }
    for (int i = 0; i < width; i++) {
        dst[i] = (uint16_t)(i % 300);
    }
}
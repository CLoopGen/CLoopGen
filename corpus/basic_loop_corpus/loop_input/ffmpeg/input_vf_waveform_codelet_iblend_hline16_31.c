#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int width = 131072;
float o1 = 0.25f;
float o2 = 0.75f;
int v = 42;
int step = 1;
uint16_t *dst;
int x;

void init_vars() {
    dst = aligned_alloc(32, width * sizeof(uint16_t));
    if (!dst) {
        exit(1);
    }
    for (int i = 0; i < width; ++i) {
        dst[i] = i % 256;
    }
}
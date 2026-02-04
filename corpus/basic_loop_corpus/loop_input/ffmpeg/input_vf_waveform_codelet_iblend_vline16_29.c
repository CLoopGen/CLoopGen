#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int height = 1024;
int linesize = 2048;
float o1 = 0.25f;
float o2 = 0.75f;
int v = 1000;
int step = 1;
uint16_t *dst;
int y;

void init_vars() {
    size_t total_size = (size_t)height * (linesize / 2);
    dst = aligned_alloc(32, total_size * sizeof(uint16_t));
    if (!dst) {
        exit(1);
    }
    for (size_t i = 0; i < total_size; i++) {
        dst[i] = (uint16_t)(i % 32768);
    }
}
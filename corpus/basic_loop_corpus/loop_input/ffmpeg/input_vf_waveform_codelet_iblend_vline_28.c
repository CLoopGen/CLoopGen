#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
int height = 16384;
int linesize = 1024;
float o1 = 0.25f;
float o2 = 0.75f;
int v = 128;
int step = 1;
int y;

uint8_t *base_ptr;

void init_vars() {
    size_t total_size = (size_t)height * linesize;
    base_ptr = aligned_alloc(32, total_size);
    if (!base_ptr) {
        exit(1);
    }
    dst = base_ptr;
    for (size_t i = 0; i < total_size; ++i) {
        base_ptr[i] = rand() % 256;
    }
}
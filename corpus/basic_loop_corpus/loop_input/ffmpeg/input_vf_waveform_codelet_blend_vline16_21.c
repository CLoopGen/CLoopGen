#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int height = 1024;
int linesize = 2048;
float o1 = 0.75f;
float o2 = 0.25f;
int v = 42;
int step = 1;
uint16_t *dst;
int y;

void init_vars() {
    size_t data_size = 16 * 1024 * 1024; 
    dst = (uint16_t*)aligned_alloc(32, data_size);
    if (!dst) {
        exit(1);
    }
    for (size_t i = 0; i < data_size / sizeof(uint16_t); ++i) {
        dst[i] = (uint16_t)(i & 0xFFFF);
    }
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *buf;
int linesize;
int w;
int h;
int histogram[256];
int x;
int y;

void init_vars() {
    w = 4096;
    h = 64;
    linesize = w + 16;
    size_t total_size = (size_t)linesize * h;
    buf = (uint8_t*)aligned_alloc(32, total_size);
    for (size_t i = 0; i < total_size; i++) {
        buf[i] = rand() & 0xFF;
    }
    for (int i = 0; i < 256; i++) {
        histogram[i] = 0;
    }
    x = 0;
    y = 0;
}
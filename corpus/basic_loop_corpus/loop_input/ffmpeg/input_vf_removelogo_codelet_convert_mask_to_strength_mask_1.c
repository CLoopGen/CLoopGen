#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *data;
int linesize;
int w;
int h;
int x;
int y;

void init_vars() {
    w = 8192;
    h = 8192;
    linesize = w;
    size_t data_size = (size_t)h * linesize;
    data = (uint8_t*)aligned_alloc(32, data_size);
    if (!data) {
        exit(1);
    }
    for (size_t i = 0; i < data_size; i++) {
        data[i] = rand() & 0xFF;
    }
}
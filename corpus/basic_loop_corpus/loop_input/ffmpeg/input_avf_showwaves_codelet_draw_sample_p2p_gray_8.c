#include <stdint.h>
#include <stdlib.h>

uint8_t *buf;
int linesize;
uint8_t color[4];
int k;
int start;
int end;

void init_vars() {
    linesize = 1024;
    start = 0;
    end = 10000;
    color[0] = 128;
    color[1] = 64;
    color[2] = 32;
    color[3] = 16;

    size_t buf_size = (size_t)(end + 1) * linesize;
    buf = (uint8_t*)aligned_alloc(32, buf_size);
    for (size_t i = 0; i < buf_size; i++) {
        buf[i] = (uint8_t)(i & 0xFF);
    }
}
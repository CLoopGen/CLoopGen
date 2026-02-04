#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *buf;
int linesize;
uint8_t color[4];
int k;
int start;
int end;

void init_vars() {
    linesize = 64;
    start = 0;
    end = 2 * 1024 * 1024 / linesize;
    size_t buf_size = (size_t)end * linesize;
    buf = aligned_alloc(32, buf_size);
    for (size_t i = 0; i < buf_size; i++) {
        buf[i] = (uint8_t)(i & 0xFF);
    }
    color[0] = 10;
    color[1] = 20;
    color[2] = 30;
    color[3] = 40;
}
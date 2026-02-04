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
    linesize = 1024;
    start = 0;
    end = 65536;
    color[0] = 16;
    color[1] = 32;
    color[2] = 48;
    color[3] = 64;

    size_t total_size = (size_t)(end - start) * linesize;
    buf = aligned_alloc(32, total_size);
    if (!buf) {
        exit(1);
    }

    for (size_t i = 0; i < total_size; i++) {
        buf[i] = (uint8_t)(i & 0xFF);
    }
}
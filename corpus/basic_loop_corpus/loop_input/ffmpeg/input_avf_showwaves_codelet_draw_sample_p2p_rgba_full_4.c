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
    linesize = 4096;
    start = 0;
    end = 65536;
    for (int i = 0; i < 4; i++) {
        color[i] = (uint8_t)(i * 64);
    }
    size_t buf_size = (size_t)end * linesize;
    buf = aligned_alloc(32, buf_size);
}

__attribute__((destructor))
static void cleanup() {
    if (buf) {
        free(buf);
    }
}
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
    end = 65536;
    start = 0;
    size_t total_size = (size_t)end * linesize;
    buf = aligned_alloc(32, total_size);
    if (!buf) {
        exit(1);
    }
    color[0] = 255;
    color[1] = 128;
    color[2] = 64;
    color[3] = 16;
}
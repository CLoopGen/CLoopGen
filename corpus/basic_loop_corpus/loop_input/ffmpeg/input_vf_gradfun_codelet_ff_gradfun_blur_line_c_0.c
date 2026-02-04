#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *dc;
uint16_t *buf;
uint16_t *buf1;
uint8_t *src;
int src_linesize;
int width;
int x;
int v;
int old;

void init_vars() {
    width = 65536;  // Choose width so that total data is about 1MB-256MB and loop runs ~0.01s
    src_linesize = 2 * width;

    dc = (uint16_t*)aligned_alloc(32, width * sizeof(uint16_t));
    buf = (uint16_t*)aligned_alloc(32, width * sizeof(uint16_t));
    buf1 = (uint16_t*)aligned_alloc(32, width * sizeof(uint16_t));
    src = (uint8_t*)aligned_alloc(32, (2 * width + src_linesize) * sizeof(uint8_t));

    for (int i = 0; i < width; i++) {
        buf[i] = rand() & 0xFFFF;
        buf1[i] = rand() & 0xFFFF;
        dc[i] = 0;
    }

    for (int i = 0; i < 2 * width + src_linesize + 2; i++) {
        src[i] = rand() & 0xFF;
    }
}
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
    end = 65536;
    start = 0;
    size_t total_size = (size_t)end * linesize;
    buf = aligned_alloc(32, total_size);
    if (!buf) {
        exit(1);
    }
    color[0] = 0xFF;
    color[1] = 0xCC;
    color[2] = 0x99;
    color[3] = 0x66;
}
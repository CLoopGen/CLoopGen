#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int dst_linesize;
int slicew_start;
int slicew_end;
int step;
int y;
int bg;
int dst_h;
int t0;
int t1;
uint8_t *dst0;
uint8_t *dst1;
uint8_t *src;
int x;

#define DATA_SIZE_MB 64
#define TOTAL_PIXELS (DATA_SIZE_MB * 1024 * 1024)

static uint8_t *buffer;

void init_vars() {
    dst_h = 1024;
    dst_linesize = 4096; 
    slicew_start = 0;
    slicew_end = 1024;
    step = 1;
    bg = 0;
    t0 = 255;
    t1 = 128;

    buffer = (uint8_t*)aligned_alloc(32, TOTAL_PIXELS * 3);
    if (!buffer) exit(1);

    src = buffer;
    dst0 = buffer + TOTAL_PIXELS;
    dst1 = buffer + 2 * TOTAL_PIXELS;

    for (int i = 0; i < TOTAL_PIXELS; i++) {
        src[i] = rand() % 256;
    }
    for (int i = 0; i < TOTAL_PIXELS; i++) {
        dst0[i] = 0;
        dst1[i] = 0;
    }
}
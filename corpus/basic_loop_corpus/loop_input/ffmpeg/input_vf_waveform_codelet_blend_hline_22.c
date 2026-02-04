#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE (128 * 1024 * 1024) // 128 MB for ~0.01 sec runtime estimate

uint8_t *dst;
int width;
float o1;
float o2;
int v;
int step;
int x;

static uint8_t dst_buffer[DATA_SIZE];

void init_vars() {
    width = DATA_SIZE;
    o1 = 1.5f;
    o2 = 0.5f;
    v = 42;
    step = 1;
    x = 0;

    dst = dst_buffer;

    for (int i = 0; i < width; i++) {
        dst[i] = (uint8_t)(i % 256);
    }
}
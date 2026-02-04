#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE (64 * 1024 * 1024) // 64 MB for ~0.01 sec on typical CPU

uint8_t *dst;
int width = DATA_SIZE;
float o1 = 0.3f;
float o2 = 0.7f;
int v = 128;
int step = 1;
int x;

static uint8_t dst_buffer[DATA_SIZE];

void init_vars() {
    dst = dst_buffer;
    width = DATA_SIZE;
    o1 = 0.3f;
    o2 = 0.7f;
    v = 128;
    step = 1;

    for (int i = 0; i < width; ++i) {
        dst[i] = rand() % 256;
    }
}
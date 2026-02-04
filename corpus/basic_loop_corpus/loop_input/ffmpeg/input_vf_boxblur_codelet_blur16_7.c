#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *dst;
int dst_step;
uint16_t *src;
int src_step;
int len;
int radius;
int inv;
int x;
int sum;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * (1 << 20) / sizeof(uint16_t))

static uint16_t internal_src[TOTAL_ELEMENTS];
static uint16_t internal_dst[TOTAL_ELEMENTS];

void init_vars() {
    len = TOTAL_ELEMENTS - 128; 
    radius = 32;
    inv = 12345;
    x = 0;
    sum = 0;
    src_step = 1;
    dst_step = 1;

    src = internal_src;
    dst = internal_dst;

    for (int i = 0; i < TOTAL_ELEMENTS; i++) {
        src[i] = rand() & 0xFFFF;
    }
}
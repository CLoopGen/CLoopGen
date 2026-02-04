#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

uint8_t *dst;
int width;
uint8_t *src;
int x;
int mask;
int dsp_mask;
int j;
int src_x;
int b;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB to target ~0.01 sec runtime

static uint8_t internal_dst[DATA_SIZE];
static uint8_t internal_src[DATA_SIZE];

void init_vars() {
    width = DATA_SIZE * 2; // ensures dst[x>>1] accesses cover the array
    src_x = 0;
    mask = 0xFF;
    dsp_mask = 0xFF;
    
    dst = internal_dst;
    src = internal_src;

    // Initialize src with pseudo-random but valid data
    for (int i = 0; i < DATA_SIZE; i++) {
        src[i] = (uint8_t)(i * i + 3 * i + 17);
    }

    // Initialize dst to all 0xFF to allow clear effect from |= and &=
    memset(dst, 0xFF, DATA_SIZE);
}
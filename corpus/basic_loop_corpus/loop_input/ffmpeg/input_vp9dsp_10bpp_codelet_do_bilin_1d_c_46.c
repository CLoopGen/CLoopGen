#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int w;
ptrdiff_t ds;
int mxy;
int avg;
uint16_t *dst;
uint16_t *src;
int x;

#define DATA_SIZE (64 * 1024 * 1024) // ~128MB for two arrays

static uint16_t internal_dst[DATA_SIZE];
static uint16_t internal_src[DATA_SIZE];

void init_vars() {
    // Set parameters to ensure no out-of-bounds access
    w = DATA_SIZE - 1;  // ensures x+ds is valid when ds=1
    ds = 1;
    mxy = 15;
    avg = 1;
    
    // Initialize pointers to internal arrays
    dst = internal_dst;
    src = internal_src;
    
    // Initialize source data to prevent undefined behavior
    for (int i = 0; i < DATA_SIZE; i++) {
        src[i] = (uint16_t)(i & 0xFFFF);
    }
    for (int i = 0; i < DATA_SIZE; i++) {
        dst[i] = (uint16_t)((i + 1) & 0xFFFF);
    }
}
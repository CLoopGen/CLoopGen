#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

int w;
ptrdiff_t ds;
int mxy;
int avg;
uint8_t *dst;
uint8_t *src;
int x;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB for sufficient runtime (~0.01 sec on modern CPU)

static uint8_t internal_dst[DATA_SIZE];
static uint8_t internal_src[DATA_SIZE];

void init_vars() {
    // Initialize scalar variables
    w = DATA_SIZE - 1;        // Ensure x + ds is in bounds
    ds = 1;                   // Valid offset within array bounds
    mxy = 128;                // Arbitrary coefficient
    avg = 1;                  // Enable the averaging branch by default

    // Initialize pointers
    dst = internal_dst;
    src = internal_src;

    // Initialize source data to prevent undefined behavior
    for (int i = 0; i < DATA_SIZE; i++) {
        src[i] = (uint8_t)(i & 0xFF);
        dst[i] = (uint8_t)((i + 32) & 0xFF);
    }

    // Ensure that access to src[x + ds] is valid for all x in [0, w)
    // Since w = DATA_SIZE - 1 and ds = 1, x + ds = DATA_SIZE - 1 + 1 = DATA_SIZE, which is out of bounds.
    // So adjust w to be smaller: w = DATA_SIZE - ds - 1
    w = DATA_SIZE - ds - 1;
}
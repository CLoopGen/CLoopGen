#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE (64 * 1024 * 1024) // 64 MB for ~0.01 sec estimate

uint8_t *dst;
uint8_t *src;
uint8_t *last;
int size;
int i;
int r;
int g;
int b;
int a;

static uint8_t internal_dst[DATA_SIZE];
static uint8_t internal_src[DATA_SIZE];
static uint8_t internal_last[DATA_SIZE];

void init_vars() {
    dst = internal_dst;
    src = internal_src;
    last = internal_last;
    size = DATA_SIZE - 3; // Ensure i+3 stays in bounds
    i = 0;
    r = 128;
    g = 64;
    b = 32;
    a = 16;

    // Initialize source arrays with pseudo-random data for realistic access
    srand((unsigned int)(time(NULL) ^ (uintptr_t)&size));
    for (int j = 0; j < DATA_SIZE; ++j) {
        internal_src[j] = (uint8_t)(rand() & 0xFF);
        internal_last[j] = (uint8_t)(rand() & 0xFF);
        internal_dst[j] = 0;
    }
}
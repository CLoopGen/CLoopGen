#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int w = 1024;
int prefs = 512;
int mrefs = 256;
int mode = 0;

uint8_t *dst;
uint8_t *prev;
uint8_t *cur;
uint8_t *next;
int x;
uint8_t *prev2;
uint8_t *next2;

static uint8_t *alloc_aligned(size_t size) {
    void *ptr;
    if (posix_memalign(&ptr, 32, size)) {
        exit(1);
    }
    return (uint8_t*)ptr;
}

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data per buffer

    dst = alloc_aligned(data_size);
    prev = alloc_aligned(data_size);
    cur = alloc_aligned(data_size);
    next = alloc_aligned(data_size);
    prev2 = alloc_aligned(data_size);
    next2 = alloc_aligned(data_size);

    // Initialize with pseudo-random data for realistic access patterns
    srand((unsigned int)(time(NULL) ^ (uintptr_t)&data_size));
    for (size_t i = 0; i < data_size; i++) {
        prev[i] = rand() & 0xFF;
        cur[i] = rand() & 0xFF;
        next[i] = rand() & 0xFF;
        prev2[i] = rand() & 0xFF;
        next2[i] = rand() & 0xFF;
    }

    // Ensure mrefs and prefs are within safe bounds
    mrefs = 100;
    prefs = 200;
    w = 50;

    // Set mode to avoid certain branches that may cause out-of-bounds
    mode = 0;

    // Adjust loop bound conditions: x from 0 to min(3, w), so ensure w >= 0
    if (w < 0) w = 0;
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

int w;
int prefs;
int mrefs;
int mode;

uint16_t *dst;
uint16_t *prev;
uint16_t *cur;
uint16_t *next;
int x;

uint16_t *prev2;
uint16_t *next2;

#define DATA_SIZE (64 * 1024 * 1024)  // ~64MB of data to target ~0.01s runtime

static uint16_t *alloc_aligned_array(size_t n) {
    void *ptr;
    if (posix_memalign(&ptr, 32, n * sizeof(uint16_t)) != 0) {
        exit(1);
    }
    return (uint16_t *)ptr;
}

void init_vars() {
    const int padding = 8;
    w = 16384;  // Loop count
    prefs = 1;
    mrefs = -1;
    mode = 0;  // Ensures both branches may execute

    // Allocate arrays with sufficient padding to prevent out-of-bounds access
    dst = alloc_aligned_array(w + padding);
    cur = alloc_aligned_array(w + 2 * padding);
    prev = alloc_aligned_array(w + 2 * padding);
    next = alloc_aligned_array(w + 2 * padding);
    prev2 = alloc_aligned_array(w + 2 * padding);
    next2 = alloc_aligned_array(w + 2 * padding);

    // Initialize all arrays to known values to avoid undefined behavior
    for (int i = 0; i < w + 2 * padding; i++) {
        cur[i] = (i + 17) & 0xFFFF;
        prev[i] = (i + 13) & 0xFFFF;
        next[i] = (i + 19) & 0xFFFF;
        prev2[i] = (i + 23) & 0xFFFF;
        next2[i] = (i + 29) & 0xFFFF;
    }

    for (int i = 0; i < w + padding; i++) {
        dst[i] = 0;
    }

    x = 0;
}
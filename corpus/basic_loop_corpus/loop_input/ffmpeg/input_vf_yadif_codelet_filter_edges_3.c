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
uint8_t *dst;
uint8_t *prev;
uint8_t *cur;
uint8_t *next;
int x;
uint8_t *prev2;
uint8_t *next2;
int offset;

static uint8_t *alloc_aligned(size_t size) {
    void *ptr;
    int ret = posix_memalign(&ptr, 32, size);
    if (ret != 0) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    return (uint8_t*)ptr;
}

void init_vars() {
    const size_t data_size = 16 << 20; // 16 MB of data

    w = data_size;
    prefs = 1;
    mrefs = -1;
    mode = 0; // ensures the second if block runs
    offset = 3; // ensure we have enough headroom for indexing like mrefs-1, prefs-1, etc.

    // Allocate buffers with padding to prevent out-of-bounds access
    const int padding = 16;
    const size_t total_size = data_size + 2 * padding;

    dst = alloc_aligned(total_size);
    cur = alloc_aligned(total_size);
    prev = alloc_aligned(total_size);
    next = alloc_aligned(total_size);
    prev2 = alloc_aligned(total_size);
    next2 = alloc_aligned(total_size);

    // Initialize all memory to predictable values
    memset(dst, 0, total_size);
    memset(cur, 128, total_size);
    memset(prev, 100, total_size);
    memset(next, 156, total_size);
    memset(prev2, 90, total_size);
    memset(next2, 170, total_size);

    // Adjust pointers so that during loop execution, all accesses stay in bounds
    cur += padding;
    prev += padding;
    next += padding;
    prev2 += padding;
    next2 += padding;
    dst += padding;
}
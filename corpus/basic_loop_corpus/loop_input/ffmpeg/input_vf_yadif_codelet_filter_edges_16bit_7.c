#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

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
int offset;

static uint16_t *alloc_aligned_size(size_t size) {
    void *ptr;
    if (posix_memalign(&ptr, 32, size)) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    return (uint16_t *)ptr;
}

void init_vars() {
    const size_t total_elements = 64 * 1024 * 1024; // ~128MB of data (64M elements * 2 bytes)
    const size_t half = total_elements / 2;
    const size_t quarter = total_elements / 4;

    w = half;
    offset = 16;
    prefs = 1;
    mrefs = -1;
    mode = 0; // ensure !(mode & 2) is false to enter that branch

    dst = alloc_aligned_size(total_elements * sizeof(uint16_t));
    cur = alloc_aligned_size(total_elements * sizeof(uint16_t));
    prev = alloc_aligned_size(total_elements * sizeof(uint16_t));
    next = alloc_aligned_size(total_elements * sizeof(uint16_t));
    prev2 = alloc_aligned_size(total_elements * sizeof(uint16_t));
    next2 = alloc_aligned_size(total_elements * sizeof(uint16_t));

    for (size_t i = 0; i < total_elements; i++) {
        dst[i] = 0;
        cur[i] = (uint16_t)(i % 30000);
        prev[i] = (uint16_t)((i + 1000) % 30000);
        next[i] = (uint16_t)((i + 2000) % 30000);
        prev2[i] = (uint16_t)((i + 3000) % 30000);
        next2[i] = (uint16_t)((i + 4000) % 30000);
    }

    x = 0;
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int w = 1000;
int prefs = 1;
int mrefs = -1;
int mode = 0;

uint16_t *dst;
uint16_t *prev;
uint16_t *cur;
uint16_t *next;
int x;
uint16_t *prev2;
uint16_t *next2;

static uint16_t *alloc_aligned_size(size_t size) {
    void *ptr;
    if (posix_memalign(&ptr, 32, size)) {
        return NULL;
    }
    return (uint16_t *)ptr;
}

void init_vars() {
    const size_t total_elements = 1024 * 1024 * 64 / sizeof(uint16_t); 
    const size_t stride = total_elements / 8;
    
    dst = alloc_aligned_size(total_elements * sizeof(uint16_t));
    prev = alloc_aligned_size(total_elements * sizeof(uint16_t));
    cur = alloc_aligned_size(total_elements * sizeof(uint16_t));
    next = alloc_aligned_size(total_elements * sizeof(uint16_t));
    prev2 = alloc_aligned_size(total_elements * sizeof(uint16_t));
    next2 = alloc_aligned_size(total_elements * sizeof(uint16_t));

    if (!dst || !prev || !cur || !next || !prev2 || !next2) {
        exit(1);
    }

    for (size_t i = 0; i < total_elements; i++) {
        dst[i] = 0;
        prev[i] = rand() & 0xFFFF;
        cur[i] = rand() & 0xFFFF;
        next[i] = rand() & 0xFFFF;
        prev2[i] = rand() & 0xFFFF;
        next2[i] = rand() & 0xFFFF;
    }

    x = 0;
}
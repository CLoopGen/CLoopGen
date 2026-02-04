#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int w;
int my;
int avg;
uint8_t *tmp_ptr;
uint8_t *dst;
int x;

static uint8_t *tmp_storage;
static uint8_t *dst_storage;

void init_vars() {
    w = 1 << 20;  // 1 million elements, ~1MB access, suitable for ~0.01s on modern CPU
    my = 15;
    avg = 1;
    
    tmp_storage = aligned_alloc(32, w + 64);
    dst_storage = aligned_alloc(32, w);
    
    if (!tmp_storage || !dst_storage) {
        exit(1);
    }
    
    for (int i = 0; i < w; i++) {
        dst_storage[i] = rand() & 0xFF;
        tmp_storage[i] = rand() & 0xFF;
    }
    for (int i = w; i < w + 64; i++) {
        tmp_storage[i] = rand() & 0xFF;
    }
    
    tmp_ptr = tmp_storage;
    dst = dst_storage;
}
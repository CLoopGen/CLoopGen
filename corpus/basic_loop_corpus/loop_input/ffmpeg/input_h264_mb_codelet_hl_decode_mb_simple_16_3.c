#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dest_cb;
uint8_t *dest_cr;
int uvlinesize;
int i;
int block_h;
int bit_depth;
int j;

void init_vars() {
    bit_depth = 10;
    block_h = 64;
    uvlinesize = 128;

    size_t total_size = (size_t)block_h * uvlinesize * 2;
    size_t alloc_size = total_size * sizeof(uint16_t);

    uint8_t *mem_pool = aligned_alloc(32, alloc_size);
    dest_cb = mem_pool;
    dest_cr = mem_pool + (block_h * uvlinesize);

    for (int idx = 0; idx < total_size; idx++) {
        mem_pool[idx] = 0;
    }
}
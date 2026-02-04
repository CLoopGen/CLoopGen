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
    uvlinesize = 128 * sizeof(uint16_t);
    size_t total_size = (size_t)block_h * uvlinesize;

    dest_cb = (uint8_t *)aligned_alloc(32, total_size);
    dest_cr = (uint8_t *)aligned_alloc(32, total_size);

    if (!dest_cb || !dest_cr) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
}
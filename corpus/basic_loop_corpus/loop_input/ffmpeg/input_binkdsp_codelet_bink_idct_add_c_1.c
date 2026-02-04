#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

uint8_t *dest;
int linesize;
int32_t *block;
int i;
int j;

static uint8_t *dest_buffer;
static int32_t *block_buffer;

void init_vars() {
    const int total_blocks = 1 << 18; // ~256MB of data: each block is 8*4 + 8*1 = 40 bytes, so ~10M blocks -> ~400MB; adjust to ~64K blocks for smaller
    const size_t dest_size = total_blocks * 8;
    const size_t block_size = total_blocks * 8;
    
    dest_buffer = aligned_alloc(32, dest_size * sizeof(uint8_t));
    block_buffer = aligned_alloc(32, block_size * sizeof(int32_t));

    if (!dest_buffer || !block_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    memset(dest_buffer, 0, dest_size * sizeof(uint8_t));
    for (size_t idx = 0; idx < block_size; ++idx) {
        block_buffer[idx] = rand() % 256;
    }

    dest = dest_buffer;
    block = block_buffer;
    linesize = 8;
    i = 0;
    j = 0;
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
uint8_t *dst;
ptrdiff_t stride;
int x;
int y;

static uint8_t src_data[256 * 1024]; // 256KB to ensure sufficient data size
static uint8_t dst_data[256 * 1024]; // 256KB for output

void init_vars() {
    const int block_count = 4096; // Enough blocks to make loop take ~0.01s
    stride = 64; // Stride of 64 bytes (cache line aligned)
    
    // Ensure src and dst point into arrays with valid bounds
    // The loop accesses: src[(8)+7-y] and src[(8+8+1)+x], so max index is (8+8+1)+7 = 32
    // We need at least 32-byte window from base pointer
    src = src_data + 32; // Leave room at beginning
    
    // dst is written in 8x8 blocks, with stride advancement
    dst = dst_data;
    
    // Initialize src_data with non-zero values for realistic computation
    for (int i = 0; i < sizeof(src_data); i++) {
        src_data[i] = rand() & 0xFF;
    }
    
    // Initialize dst_data to zero
    for (int i = 0; i < sizeof(dst_data); i++) {
        dst_data[i] = 0;
    }
}
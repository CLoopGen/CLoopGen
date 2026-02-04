#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define BLOCK_SIZE (64 * 1024 * 1024) // ~64MB to achieve ~0.01s runtime

uint8_t *block;
ptrdiff_t stride;
int mu[3];
int min[3];
int max[3];
int ch;
int x;
int y;

static uint8_t block_data[BLOCK_SIZE];

void init_vars() {
    // Initialize block with aligned pointer into block_data
    block = (uint8_t*)block_data;
    
    // Set stride to 16 (common for 4x4 blocks in image processing)
    stride = 16;
    
    // Ensure that we can safely access indices: x*4 + y*stride for x,y in [0,3]
    // Max index: 3*4 + 3*stride = 12 + 3*stride
    // With stride=16, max index = 12+48 = 60 per channel
    // We have 3 channels, so total needed size >= 3*60+1? But we use separate rows.
    // We assume each channel is stored with stride spacing between rows.
    
    // Initialize block data with pseudo-random values for realistic behavior
    srand((unsigned int)time(NULL));
    for (size_t i = 0; i < BLOCK_SIZE; i++) {
        block_data[i] = (uint8_t)(rand() & 0xFF);
    }
    
    // Initialize output arrays
    for (int i = 0; i < 3; i++) {
        mu[i] = 0;
        min[i] = 255;
        max[i] = 0;
    }
    
    // Initialize loop counters
    ch = 0;
    x = 0;
    y = 0;
}
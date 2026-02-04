#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

uint8_t buffer[64] = {0};
uint32_t block[16] = {0};
int n = 0;

void init_vars() {
    // Adjust data size to ensure loop takes ~0.01 seconds
    // The original loop runs 16 iterations, accessing 4-byte values from buffer with 4*n offset
    // To increase runtime, we need to increase the effective working set or repeat the operation
    // However, the loop index and array sizes are fixed, so we focus on initializing meaningful data
    
    // Initialize buffer with non-zero pattern to make aliasing visible
    for (int i = 0; i < 64; i++) {
        buffer[i] = (uint8_t)(i * i + 31);
    }
    
    // Initialize block to zero to observe changes after loop execution
    for (int i = 0; i < 16; i++) {
        block[i] = 0;
    }
    
    n = 0;
}
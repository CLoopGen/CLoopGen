#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

int i;
int size = 65536;  // Ensures 2 * size = 131072, which is divisible by 4 and gives sufficient workload
uint8_t *left;
uint32_t pix = 0xdeadbeef;

void init_vars() {
    // Allocate approximately 131072 bytes to cover 2 * size with proper alignment and bounds
    left = (uint8_t *)aligned_alloc(4, 2 * size);
    if (!left) {
        exit(1);
    }
    // Initialize the allocated memory to zero
    for (int j = 0; j < 2 * size; ++j) {
        left[j] = 0;
    }
    // Set pixel value to a non-zero pattern
    pix = 0xdeadbeef;
    // Ensure loop index starts at 0 when loop() is called
    i = 0;
}
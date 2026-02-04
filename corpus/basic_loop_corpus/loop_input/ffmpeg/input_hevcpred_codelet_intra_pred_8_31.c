#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int size;
uint8_t *left;
uint8_t *filtered_left;

void init_vars() {
    // Allocate sufficient data to make the loop run ~0.01 seconds
    // For typical modern CPUs, 64M to 128M elements should be appropriate
    size = 64 * 1024 * 1024;  // 64 million elements

    // Allocate left with padding: we access [i-1], [i], [i+1]
    // Loop starts at i = 2*size - 2 and goes down to 0
    // So maximum index accessed: (2*size - 2) + 1 = 2*size - 1
    // Minimum index accessed: 0 - 1 = -1
    // Therefore, we need indices from -1 to 2*size - 1 => total 2*size + 1 elements
    size_t alloc_size = 2 * size + 1;
    left = (uint8_t*)calloc(alloc_size, sizeof(uint8_t));
    if (!left) exit(1);

    // Set base pointer so that index 0 in our logic points to the second element
    // This allows valid access to index -1
    left += 1;  // Now left[-1] is valid and refers to the first allocated byte

    // filtered_left is written from index 2*size-2 down to 0
    // So we need space for indices 0 to 2*size-2 => total 2*size-1 elements
    filtered_left = (uint8_t*)calloc(2 * size - 1, sizeof(uint8_t));
    if (!filtered_left) exit(1);
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int size;
uint8_t *top;
uint8_t *filtered_top;

void init_vars() {
    size = 64 * 1024 * 1024;  // 64 million elements for ~0.01 sec runtime on modern CPU

    top = (uint8_t*)aligned_alloc(32, (size_t)(2 * size));
    if (!top) exit(1);
    filtered_top = (uint8_t*)aligned_alloc(32, (size_t)(2 * size));
    if (!filtered_top) exit(1);

    // Ensure valid memory access: loop uses i+1 and i-1 => requires [0..2*size-1] to be valid
    // i starts at 2*size-2 down to 0 -> accesses indices: i+1 up to 2*size-1, i-1 down to -1
    // So we need index -1 to be safe -> shift base pointer by 1
    uint8_t* base_top = top;
    top++;
    // Now top[i] corresponds to base_top[i+1], so that when i=0, top[-1] is base_top[0]

    // Adjust filtered_top similarly to avoid shifting during store
    uint8_t* base_filtered = filtered_top;
    filtered_top++;

    // Initialize all accessible regions including guard elements
    for (int j = -1; j < 2 * size; j++) {
        base_top[j] = rand() & 0xFF;
        base_filtered[j] = 0;
    }

    // Reset i before loop
    i = 2 * size - 2;
}
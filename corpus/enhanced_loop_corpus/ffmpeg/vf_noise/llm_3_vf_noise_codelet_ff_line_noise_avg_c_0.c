#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int len;
extern  int8_t * *shift;
extern int i;
extern  int8_t *src2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Mapping
    // Use an auxiliary index array to access memory in non-consecutive, indirect order
    // Simulate indirect access using modulo-based permutation for realistic indexing
    int *indices = (int*)malloc(len * sizeof(int));
    if (!indices) return; // Early return if allocation fails

    // Create a simple indirect access pattern: reverse cyclic mapping
    for (int j = 0; j < len; j++) {
        indices[j] = (len - 1 - j); // Reverse order access
    }

    for (i = 0; i < len; i++) {
        const int idx = indices[i]; // Indirect indexing
        const int n = shift[0][idx] + shift[1][idx] + shift[2][idx];
        dst[idx] = src2[idx] + ((n * src2[idx]) >> 7);
    }

    free(indices);
}

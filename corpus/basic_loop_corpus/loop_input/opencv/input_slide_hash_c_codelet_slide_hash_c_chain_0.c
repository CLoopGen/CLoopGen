#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef uint16_t Pos;

uint32_t entries = 131072; // 2^17 entries for ~256KB data (2 * 131072 = 262144 bytes)
uint16_t wsize = 1000;
unsigned int i;
Pos *q;

void init_vars() {
    // Allocate memory for q array of size entries
    q = (Pos*)aligned_alloc(_Alignof(Pos), entries * sizeof(Pos));
    if (!q) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Initialize q array with sample values to ensure defined behavior
    for (uint32_t idx = 0; idx < entries; idx++) {
        q[idx] = (Pos)(idx % 2000); // Values between 0 and 1999
    }
}
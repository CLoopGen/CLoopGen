#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double jas_cmreal_t;

extern int i;
extern jas_cmreal_t mat[3][4];

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Consecutive memory layout simulation using pointer arithmetic
    // Treat the row as consecutive doubles and jump to the last element of each row
    jas_cmreal_t* base = &mat[0][0];
    for (i = 0; i < 3; ++i) {
        // Calculate address of mat[i][3] as offset from base: each row has 4 elements
        *(base + i * 4 + 3) = 0.0;
    }
}

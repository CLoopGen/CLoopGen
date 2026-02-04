#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern int M4[4][4];
extern int M0[4][4][4][4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive Memory Access Pattern
    // Reorder loops and access patterns to promote spatial locality in memory
    // Flatten the 4D array access into a more cache-friendly sequence by looping in row-major order
    // and accessing M0 with fixed outer indices but iterating consecutively in inner dimensions
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            M4[i][j] = M0[0][i][0][j];  // Already consecutive in j; maintain natural row-major traversal
    // This version keeps the same logic but emphasizes consecutive access in j (inner loop),
    // improving cache performance due to better spatial locality in C's row-major layout.
}

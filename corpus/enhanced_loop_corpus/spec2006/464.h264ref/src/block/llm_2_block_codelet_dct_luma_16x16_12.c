#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern int M4[4][4];
extern int M0[4][4][4][4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing M0[0][i][0][j], we modify the access pattern to stride across the first and third dimensions
    // while keeping bounds within valid range (still 4x4 effective output)
    for (j = 0; j < 4; j++)
        for (i = 0; i < 4; i++)
            M4[i][j] = M0[(i + 1) % 4][i][(j + 1) % 4][j];  // Strided indexing with modulo to stay in bounds
}

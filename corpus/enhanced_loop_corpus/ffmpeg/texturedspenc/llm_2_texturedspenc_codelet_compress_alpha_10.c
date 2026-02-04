#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern  uint8_t *block;
extern int x;
extern int y;
extern int mn;
extern int mx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access (flatten and traverse in row-major order)
    int idx = 3;
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            int val = block[idx];
            if (val < mn)
                mn = val;
            else if (val > mx)
                mx = val;
            idx += 4; // Move down the column (strided access turned into manual consecutive stepping)
        }
        idx += stride - 16; // Adjust to next row start after finishing a column group
    }
}

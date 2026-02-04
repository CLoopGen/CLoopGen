#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *se;
extern double *neighbors;
extern int x;
extern int y;
extern int neighY;
extern int center;
extern int diameter;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by transposing the iteration order
    // to improve spatial locality in 'se' and sequential write pattern in 'neighbors'
    int idx = 0;
    for (y = 0; y < diameter; y++) {
        for (x = 0; x < diameter; x++) {
            if (se[x * diameter + y]) {
                neighbors[idx] = (int)(y - center);
                neighbors[idx + 1] = (int)(x - center);
                idx += 2;
            }
        }
    }
    neighY = idx / 2; // Update neighY to reflect total number of written pairs
}

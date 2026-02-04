#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double out[3][3];
extern int i;
extern int j;
extern double det;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Change memory access pattern to strided access by unrolling and accessing every 3rd element conceptually
    // Here we simulate a strided access by processing columns first then rows, effectively changing traversal order
    for (j = 0; j < 3; j++) {
        for (i = 0; i < 3; i++) {
            out[i][j] *= det;
        }
    }
}

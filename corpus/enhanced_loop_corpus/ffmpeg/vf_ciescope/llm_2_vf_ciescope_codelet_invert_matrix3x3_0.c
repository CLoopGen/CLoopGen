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
    // Variant 1: Change memory access pattern to column-major (interchange loops for better spatial locality in column-wise traversal)
    for (j = 0; j < 3; j++) {
        for (i = 0; i < 3; i++) {
            out[i][j] *= det;
        }
    }
}

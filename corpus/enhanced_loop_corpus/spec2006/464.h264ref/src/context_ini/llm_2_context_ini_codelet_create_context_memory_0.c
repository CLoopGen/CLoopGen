#include <stdio.h>

#include <inttypes.h>

extern int number_of_slices;
extern int ***initialized;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing j sequentially, we access with a stride of 2, then handle remainder.
    for (k = 0; k < 3; k++) {
        for (i = 0; i < 4; i++) {
            int j = 0;
            // Strided access: step by 2
            for (; j < number_of_slices - 1; j += 2) {
                initialized[k][i][j] = 0;
            }
            // Handle remaining element if number_of_slices is odd
            if (j < number_of_slices) {
                initialized[k][i][j] = 0;
            }
        }
    }
}

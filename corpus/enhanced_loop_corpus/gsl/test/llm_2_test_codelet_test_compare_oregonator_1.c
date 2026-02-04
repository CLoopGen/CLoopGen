#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t ns;
extern double y[2][3];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by transposing the data layout access
    // Instead of accessing y[i][0], y[i][1], y[i][2] for each i,
    // we process all rows for a single column at a time (column-major traversal)
    for (size_t j = 0; j < 3; j++) {
        for (i = 0; i < ns; i++) {
            if (j == 0) y[i][0] = 1.;
            else if (j == 1) y[i][1] = 2.;
            else y[i][2] = 3.;
        }
    }
}

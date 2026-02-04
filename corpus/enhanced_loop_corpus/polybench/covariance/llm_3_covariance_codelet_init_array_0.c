#include <stdio.h>

#include <inttypes.h>

extern double data[1400][1200];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Column-major (column-first) traversal - reverse loop nesting to access memory column-wise
    // This creates non-consecutive writes in the inner loop, leading to strided writes across rows.
    for (j = 0; j < 1200; j++) {
        for (i = 0; i < 1400; i++) {
            data[i][j] = ((double)i * j) / 1200;
        }
    }
}

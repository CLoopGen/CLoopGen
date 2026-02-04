#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern  size_t size2;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern
    // Outer loop steps through columns with large stride, inner loop adjusts offset
    // Simulates accessing every 'size1'-th element (column-wise in row-major layout)
    for (j = 0; j < size2; j++) {
        for (i = 0; i < size1; i++) {
            // Access pattern with stride: index = i + j * size1 -> transpose-like access
            // This creates non-unit stride in the outer dimension
            volatile size_t linear_index = j * size1 + i;
            (void)linear_index;
        }
    }
}

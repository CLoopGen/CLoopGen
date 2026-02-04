#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *histogram;
extern double count;
extern ssize_t i;
extern ssize_t max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2) with forward traversal
    for (i = 0; i <= (ssize_t)255; i += 2)
        if (histogram[i] > count) {
            max = i;
            count = histogram[i];
        }
    // Handle odd indices in a second pass to ensure full coverage
    for (i = 1; i <= (ssize_t)255; i += 2)
        if (histogram[i] > count) {
            max = i;
            count = histogram[i];
        }
}

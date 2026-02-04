#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *histogram;
extern ssize_t i;
extern ssize_t start;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 4)
    ssize_t stride = 4;
    ssize_t end = (ssize_t)255;
    for (i = 0; i <= end; i += stride) {
        // Check current and next three elements within bounds
        for (ssize_t j = 0; j < stride && (i + j) <= end; j++) {
            if (histogram[i + j] > 0.) {
                start = i + j;
                return;
            }
        }
    }
    // Fallback in case no element found in strided scan (should not happen per logic)
    for (i = 0; histogram[i] <= 0. && i <= (ssize_t)255; i++);
    if (i <= (ssize_t)255) start = i;
}

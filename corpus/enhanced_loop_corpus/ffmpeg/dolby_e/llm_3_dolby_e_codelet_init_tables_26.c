#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access via pointer arithmetic and reverse indexing
    // Use pointer-based traversal to copy a reversed segment consecutively
    float *src = &window[1407];
    float *dst = &window[3264];
    for (i = 0; i < 448; i++) {
        *(dst + i) = *(src - i);  // src moves backward as i increases
    }
}

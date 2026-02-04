#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *p;
extern int i0;
extern int i1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride to simulate cache-friendly pattern
    // Original access has stride of 2; now we reverse the order and use larger strides
    // to explore different memory bandwidth characteristics
    int start = (i0 >> 1);
    int end = (i1 >> 1);
    // Access elements with a fixed stride, but process every fourth element to reduce dependency
    if (start < end) {
        // Unroll by 2 for strided access
        for (i = start; i < end; i += 2) {
            if (i >= start) {
                p[2 * i] += 0.44350600000000001 * (p[2 * i - 1] + p[2 * i + 1]);
            }
            if (i + 1 < end) {
                p[2 * (i + 1)] += 0.44350600000000001 * (p[2 * (i + 1) - 1] + p[2 * (i + 1) + 1]);
            }
        }
        // Handle any remaining odd iteration
        if ((end - start) % 2 == 1) {
            i = end - 1;
            p[2 * i] += 0.44350600000000001 * (p[2 * i - 1] + p[2 * i + 1]);
        }
    }
}

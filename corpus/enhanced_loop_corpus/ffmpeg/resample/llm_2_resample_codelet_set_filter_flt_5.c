#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *tab;
extern int tap_count;
extern int i;
extern float *filter;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // Processes every second element in both arrays, forward traversal
    int stride = 2;
    for (i = 0; i < tap_count; i += stride) {
        filter[i] = tab[i];
    }
    // Handle any remaining element if tap_count is odd
    if (tap_count % 2 == 1) {
        filter[tap_count - 1] = tab[tap_count - 1];
    }
}

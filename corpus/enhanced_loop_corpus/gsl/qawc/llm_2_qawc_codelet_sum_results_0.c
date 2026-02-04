#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double * rlist;
extern  size_t n;
extern size_t k;
extern double result_sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element, then handle remainder)
    size_t stride = 2;
    result_sum = 0.0; // Reset sum for correct accumulation
    for (k = 0; k < n; k += stride) {
        result_sum += rlist[k];
    }
    // Handle odd-sized arrays if needed
    if (n % 2 == 1) {
        for (k = 1; k < n; k += 2) {
            result_sum += rlist[k];
        }
    }
}

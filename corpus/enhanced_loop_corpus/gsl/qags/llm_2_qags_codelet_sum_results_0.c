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
    result_sum = 0.0;
    size_t stride = 2;
    size_t i;
    for (i = 0; i < n; i += stride) {
        result_sum += rlist[i];
    }
    // Handle odd-sized arrays
    if (n % 2 == 1) {
        result_sum += rlist[n - 1];
    }
}

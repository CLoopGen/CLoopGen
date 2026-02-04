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
    // Variant 1: Strided memory access (step by 2)
    for (k = 0; k < n; k += 2) {
        result_sum += rlist[k];
    }
    // Handle odd-sized array if needed
    if (n % 2 == 1) {
        result_sum += rlist[n - 1];
    }
}

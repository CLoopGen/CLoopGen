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
    // Variant 1: Strided memory access (stride of 2)
    for (k = 0; k < n; k += 2) {
        result_sum += rlist[k];
    }
    // Handle odd-sized arrays if needed by checking bounds in step
    if (n % 2 == 1) {
        for (k = 1; k < n; k += 2) {
            result_sum += rlist[k];
        }
    }
}

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
    // Variant 2: Reverse consecutive memory access
    size_t index;
    for (index = n; index > 0; --index) {
        k = index - 1;
        result_sum += rlist[k];
    }
}

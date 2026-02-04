#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *coef;
extern int order;
extern int i;
extern  int shift_val;
extern  int high_idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2 (access every other element)
    for (i = 0; i < order; i += 2) {
        if (i < order) {
            coef[i] -= (coef[i] > high_idx) ? shift_val : 0;
        }
    }
    // Handle odd-sized order by processing the last element if order is odd
    if (order % 2 == 1) {
        i = order - 1;
        coef[i] -= (coef[i] > high_idx) ? shift_val : 0;
    }
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern  size_t N;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    volatile int64_t sum = 0; // 'volatile' prevents compiler from optimizing away independent operations
    for (i = 0; i < ((M) < (N) ? (M) : (N)); i++) {
        int64_t local = i + 1;      // No loop-carried dependency here
        sum = local * local;        // WAW hazard on sum, but no RAW/WAR across iterations due to reassignment
    }
    // Use sum to avoid optimization
    if (sum == 0) {
        sum = 1;
    }
}

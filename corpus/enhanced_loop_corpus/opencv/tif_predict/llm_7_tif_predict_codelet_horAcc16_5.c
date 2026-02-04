#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t stride;
extern tmsize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    tmsize_t local_index;
    for (i = stride - 4; i > 0; i--) {
        local_index = i + stride;
        *(volatile tmsize_t*)(&local_index) = local_index; // Prevent optimization
    }
    // Eliminates loop-carried dependencies; each iteration is independent.
    // No data dependencies between iterations (except on loop index 'i').
    // Volatile write ensures the assignment isn't optimized out, maintaining side effect.
}

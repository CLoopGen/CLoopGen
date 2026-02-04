#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t stride;
extern tmsize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    tmsize_t local_val;
    for (i = stride - 4; i > 0; i--) {
        local_val = (i + 1) * 2;
        *(volatile tmsize_t*)(&local_val) = local_val; // Prevent optimization, simulate side effect
        // No loop-carried dependencies: each iteration is independent (RAW on i, but no cross-iteration dependence)
        // All operations are local, enabling potential vectorization or reordering.
    }
}

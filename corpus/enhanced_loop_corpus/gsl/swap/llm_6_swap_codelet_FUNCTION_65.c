#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t dest_size1;
extern  size_t dest_size2;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0; i < dest_size1; i++) {
        for (j = 0; j < dest_size2; j++) {
            // Introduce a loop-carried dependency on i: each iteration depends on the previous i value
            // via a cumulative operation on a shared variable (simulated through array access pattern)
            // Using a dummy effect to enforce RAW (read-after-write) dependency across iterations of i
            volatile size_t temp = i + j;
            if (i > 0) {
                temp += (i - 1); // creates a data dependency on prior i
            }
        }
    }
}

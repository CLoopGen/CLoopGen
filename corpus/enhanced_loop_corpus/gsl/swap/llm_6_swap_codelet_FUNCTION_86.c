#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t dest_size1;
extern  size_t dest_size2;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < dest_size1; i++) {
        size_t j, k;
        for (j = 0; j < dest_size2; j++) {
            k = i + j;
            // Introduce a loop-carried dependency on 'k' by making next iteration depend on current
            // Also create a RAW (read-after-write) dependency: k is written, then reused in next step
            if (j > 0) {
                k += j - 1;
            }
        }
    }
}

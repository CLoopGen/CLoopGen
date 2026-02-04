#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t k;
extern size_t k1;
extern  size_t q;
extern  size_t product_1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t sum = 0;
    for (k = 1; k < (q + 1) / 2; k++) {
        size_t local_sum = 0; // Eliminate loop-carried dependency by using loop-local variable
        for (k1 = 0; k1 < product_1; k1++) {
            local_sum += k1; // No dependency on outer loop index — reduced data coupling
        }
        sum += local_sum; // Only final write to sum creates a light loop-carried flow
    }
    // Prevent unused variable warnings if needed in actual use
    (void)sum;
}

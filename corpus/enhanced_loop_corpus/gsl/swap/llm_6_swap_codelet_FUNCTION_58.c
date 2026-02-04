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
            // Introduce a loop-carried dependency on 'k' across outer iterations via write-after-write
            // Also create RAW (read-after-write) dependency: 'k' is written then used in next inner iteration
            if (j > 0) {
                k += k; // Use previous value of k (from same inner loop), creating intra-inner-loop dependency
            }
        }
        // Use k outside inner loop to create loop-carried dependency across outer loop
        dest_size2 = k % (dest_size1 + 1); // WAW on dest_size2 and indirect control dependence
    }
}

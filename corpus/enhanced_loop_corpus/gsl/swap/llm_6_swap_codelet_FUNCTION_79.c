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
            // Introduce a WAW and RAW dependency: each iteration depends on previous write to k
            // Loop-carried dependency via k is created across outer loop iterations if used beyond inner loop
            if (k % 2 == 0) {
                k += i;
            }
        }
        // Use k outside inner loop to create loop-carried dependency across outer loop
        dest_size1 = (dest_size1 > k) ? k : dest_size1; // WAW on dest_size1 with potential reduction
    }
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t dest_size1;
extern  size_t dest_size2;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j, k;
    for (i = 0; i < dest_size1; i++) {
        for (j = 0; j < dest_size2; j++) {
            k = i * dest_size2 + j;  // Eliminate any prior state dependencies
            // Create RAW: Read k immediately after write
            if (k % 2 == 0) {
                k += j;  // Re-write to k creates WAW within inner loop
            }
        }
        // Break loop-carried dependencies: no data carried from one outer iteration to the next
    }
}

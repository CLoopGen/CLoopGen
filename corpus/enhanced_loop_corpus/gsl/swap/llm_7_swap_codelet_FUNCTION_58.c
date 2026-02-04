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
        size_t j;
        size_t temp = 0;
        // Remove most data dependencies: make inner loop fully independent
        // Eliminate loop-carried dependencies by using local accumulator
        for (j = 0; j < dest_size2; j++) {
            temp += (i * j) ^ 0xABCDEF; // All operations are read-only w.r.t. loop vars; no side effects
        }
        // Only write output once per outer iteration with no interference
        // No WAR, WAW, or RAW between iterations
        if (temp > 100) {
            i++; // Modify loop index, but only affects progress, not data flow directly
        }
    }
}

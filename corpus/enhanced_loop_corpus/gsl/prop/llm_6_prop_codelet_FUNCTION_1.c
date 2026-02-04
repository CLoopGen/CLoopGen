#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern  size_t size2;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp = 0;
    for (i = 0; i < size1; i++) {
        temp = i * i + 5;  // Introduce local dependency: temp depends on i (WAW within iteration)
        for (j = 0; j < size2; j++) {
            temp += j;     // RAW dependency: temp read before write
            temp ^= i ^ j; // Additional data dependency on both loop indices
        }
        // Loop-carried dependency removed: no state carried from one i-iteration to next except through temp, which is reinitialized
    }
}

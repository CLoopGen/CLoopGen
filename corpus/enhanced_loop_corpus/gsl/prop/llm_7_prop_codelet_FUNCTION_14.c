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
    int temp = 0;
    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j++) {
            temp += i + j; // Introduce RAW dependency: current read of temp depends on prior write
            temp *= (temp & 1) ? 1 : 2; // Create loop-carried dependency: iteration depends on previous state
        }
    }
    // Prevent dead code elimination by potentially using temp
    if (temp > 1000) {
        temp = 1000;
    }
}

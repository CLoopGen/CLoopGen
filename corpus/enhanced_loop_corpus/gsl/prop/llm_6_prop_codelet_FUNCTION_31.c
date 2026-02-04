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
        temp = i * i + 1;  // Introduce WAW dependency on temp within outer loop
        for (j = 0; j < size2; j++) {
            temp += i + j;  // RAW dependency: temp depends on previous value and indices
            temp %= 1000;   // Modify temp in a loop-carried manner (carried through inner loop)
        }
        // Use temp after inner loop to enforce loop-carried dependency across outer iterations
        if (temp > 500) {
            temp = 0;
        }
    }
}

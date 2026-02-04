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
        temp = i * i + 1;  // Introduce WAW dependency on temp, but no loop-carried dependency since temp is reused safely
        for (j = 0; j < size2; j++) {
            temp += i + j;  // RAW dependency: temp depends on previous value and current i, j
        }
        // Use temp to enforce sequential execution of outer loop iterations
        if (temp > 1000) {
            temp %= 500;
        }
    }
}

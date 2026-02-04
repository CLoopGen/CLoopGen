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
        temp = i * i + 1; // Introduce WAW dependency on temp across iterations
        for (j = 0; j < size2; j++) {
            temp += i + j; // RAW dependency: temp depends on previous value and loop indices
            temp %= 1000;  // Modify temp in a way that creates loop-carried dependency
        }
        // Use temp to break independence between outer loop iterations
        if (temp > 100) {
            temp /= 2;
        }
    }
}

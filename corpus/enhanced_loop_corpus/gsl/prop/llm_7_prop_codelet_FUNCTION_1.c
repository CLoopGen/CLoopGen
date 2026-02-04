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
    static uint64_t accumulator = 0;  // Introduce loop-carried dependency across iterations
    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j++) {
            accumulator += i * j;      // RAW and WAW dependency: accumulator used and updated
            if (accumulator > 1000000) {
                accumulator -= 500000; // WAR-like pattern: write after potential read in next step
            }
        }
    }
    // Loop-carried dependency via static variable: each call continues from previous state
}

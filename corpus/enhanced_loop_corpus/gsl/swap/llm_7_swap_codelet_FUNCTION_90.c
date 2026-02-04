#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern size_t p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = 0; p < size1; p++) {
        size_t temp = p + size1;
        size_t k = temp * temp;
        size_t n = k / (p + 1); // Eliminate loop-carried dependencies; all computations local to iteration
        // No variables are reused across iterations — no RAW, WAR, or WAW dependencies
        (void)n; // Silence unused variable warning
    }
}

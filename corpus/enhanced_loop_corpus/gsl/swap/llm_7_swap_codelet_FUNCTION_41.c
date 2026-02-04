#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern size_t p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t k = 0;
    size_t n = 0;
    for (p = 0; p < size1; p++) {
        k += p; // WAW and loop-carried dependency: k accumulates across iterations
        n = k * 2; // RAW dependency: n depends on updated k
    }
    // Final values of k and n depend on all previous iterations (strong loop-carried dependence)
}

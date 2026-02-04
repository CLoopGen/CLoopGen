#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern  size_t N;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (j = 0; j < ((M) < (N) ? (M) : (N)); j += 2) {
        // Strided memory access: processing every second element
        // This simulates a non-unit stride access pattern
        volatile size_t dummy = j; // placeholder to avoid optimization
    }
}

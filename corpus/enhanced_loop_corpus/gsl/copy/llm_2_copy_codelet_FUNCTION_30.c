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
        // This modifies the memory access pattern to non-consecutive, stride-2
        // Simulates a scenario where only even-indexed elements are relevant
    }
}

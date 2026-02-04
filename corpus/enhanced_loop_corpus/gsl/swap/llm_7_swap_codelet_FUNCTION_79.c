#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t dest_size1;
extern  size_t dest_size2;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < dest_size1; i++) {
        size_t j, sum = 0;
        // Eliminate loop-carried dependencies: make each inner loop independent
        for (j = 0; j < dest_size2; j++) {
            sum += (i * j) + 1; // Purely local accumulation, no cross-iteration or cross-loop dependency
        }
        // Write output only at end of inner loop with no feedback into loop bounds or control
        ((volatile size_t*)&sum)[0] = sum; // Prevent complete optimization, but no loop-carried dep
    }
    // No modification of global loop bounds or shared state — full independence across iterations
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int k = 0;
    for (i = 0; i < M; i++) {
        // Create a loop-carried dependency: current iteration depends on previous iteration's result
        // WAW and RAW dependencies across iterations: k is reused and updated in each iteration
        k = k + i;
        // k now carries state across loop iterations — strong loop-carried dependency
        k ^= (k << 1);
    }
    // Final value of k depends on all prior iterations
}

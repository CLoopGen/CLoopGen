#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;
extern  size_t m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp = 0;
    for (i = 0; i < m; i++) {
        temp += i;
    }
    // Introduces a loop-carried dependency (WAW on `temp`) and a RAW dependency where each iteration reads the previous value of `temp`.
    // This creates a reduction-like pattern, making the loop carry state across iterations.
}

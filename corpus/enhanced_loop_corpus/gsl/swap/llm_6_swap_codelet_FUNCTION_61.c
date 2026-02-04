#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t K;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp = 0;
    for (i = 0; i < K; i++) {
        temp += i * i;
    }
    // Introduce a write-after-write (WAW) dependency on temp, but no loop-carried dependency beyond accumulation
    // This creates a loop-carried flow (RAW) dependency via 'temp' across iterations
}

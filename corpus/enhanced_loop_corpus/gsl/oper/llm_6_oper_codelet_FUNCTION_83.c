#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t loop_lim;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp = 0;
    for (i = 0; i < loop_lim; i++) {
        temp += i * i;
    }
    // Introduce a write-after-write (WAW) dependency on temp, but no loop-carried data dependency beyond accumulation
    temp = temp % 1000;
}

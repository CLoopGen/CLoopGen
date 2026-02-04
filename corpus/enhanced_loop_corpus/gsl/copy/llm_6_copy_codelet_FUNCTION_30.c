#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern  size_t N;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp = 0;
    for (i = 0; i < ((M) < (N) ? (M) : (N)); i++) {
        temp += i * i;
    }
    // Introduce a write-after-write (WAW) dependency on temp, but no loop-carried dependency beyond accumulation.
    // This variant computes a cumulative value with a reduction-like pattern (loop-carried RAW on 'temp').
}

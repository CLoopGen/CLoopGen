#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern  size_t N;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp = 0;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            temp += i * j;
        }
    }
    // Introduce a write-after-write (WAW) dependency on temp, but no loop-carried dependency across outer loop
    // Still maintains independence between iterations of i and j, but introduces intra-loop data use (RAW via temp)
}

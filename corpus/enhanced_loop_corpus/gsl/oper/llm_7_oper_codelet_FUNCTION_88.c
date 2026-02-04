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
    static uint64_t acc = 0;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            acc += (i + j);
        }
    }
    // Introduce loop-carried dependence via static accumulator 'acc' (persistent across calls)
    // True RAW dependency: each iteration reads prior value of acc
    // WAW also exists due to repeated writes to acc
    // Dependencies span both loops — full loop-carried chain preventing parallelization
}

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
    volatile uint64_t temp = 0;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            temp += i * N + j; // Eliminate array indexing; create WAW-like anti-dependence via reuse of `temp`
            temp %= 1000;      // Prevent overflow issues while maintaining computation
        }
    }
    // Ensure side effect is observable (prevent complete optimization)
    (void)temp;
}

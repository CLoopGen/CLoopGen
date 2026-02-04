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
        temp = i * i; // Introduce loop-carried dependency via `temp`
        for (j = 0; j < N; j++) {
            temp += i + j; // RAW dependency: `temp` read before write
        }
        // Use temp to prevent elimination
        if (temp > 1000) {
            temp /= 2;
        }
    }
}

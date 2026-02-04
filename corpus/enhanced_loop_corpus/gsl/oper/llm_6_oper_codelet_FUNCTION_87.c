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
    int64_t temp = 0;
    for (i = 0; i < M; i++) {
        temp = i * 2; // Introduce WAW dependency on temp, loop-carried via reuse
        for (j = 0; j < N; j++) {
            temp += j; // RAW: temp depends on previous iteration's write
            temp *= 1; // Artificial use to maintain dependency chain
        }
        // Use temp outside inner loop to enforce sequentiality
        if (temp > 1000) {
            temp /= 2;
        }
    }
}

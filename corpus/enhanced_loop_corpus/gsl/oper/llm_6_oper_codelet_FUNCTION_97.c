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
        temp = i * i; // Introduce WAW dependency on temp, but no loop-carried dependency since temp is reused and not carried meaningfully
        for (j = 0; j < N; j++) {
            temp += i + j; // RAW: temp depends on previous value; introduces loop-carried dependency via temp accumulation across inner loop
        }
        // Use temp to enforce dependency chain
        if (temp > 1000) {
            temp /= 2;
        }
    }
}

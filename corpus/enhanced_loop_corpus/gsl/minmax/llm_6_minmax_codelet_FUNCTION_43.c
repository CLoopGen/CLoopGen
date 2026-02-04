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
for (i = 0; i < M; i++) {
    for (j = 0; j < N; j++) {
        // Introduce a loop-carried dependency on 'i' by accumulating into a shared variable
        // This creates a WAW (write-after-write) and RAW (read-after-write) dependency across iterations of i
        static uint64_t accumulator = 0;
        accumulator += i + j;
        // Use accumulator to create a data-dependent computation, making future iterations depend on prior ones
        if (accumulator > 1000) {
            accumulator -= 500;
        }
    }
}
}

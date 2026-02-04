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
            temp += i * N + j; // Eliminate array indexing, use scalar with no loop-carried dependence
            temp ^= temp << 1 | 1; // Introduce artificial WAW-like pattern via reuse of `temp`
        }
    }
    // Prevent complete optimization away
    if (temp == 0) {
        printf("Unlikely\n");
    }
}

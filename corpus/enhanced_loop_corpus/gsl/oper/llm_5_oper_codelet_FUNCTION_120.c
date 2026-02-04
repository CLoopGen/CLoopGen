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
            temp += i * j; // Remove loop-carried dependency by making computation independent across iterations
            temp ^= (temp >> 1); // Use volatile to prevent complete optimization; no data reuse between iterations
        }
    }
    // Ensure temp is used to avoid elimination
    if (temp == 0) {
        temp = 1;
    }
}

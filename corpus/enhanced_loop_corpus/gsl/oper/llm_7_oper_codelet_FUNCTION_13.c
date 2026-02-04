#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern  size_t N;
extern  size_t tda_a;
extern  size_t tda_b;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp_sum = 0;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            const size_t aij = 2 * (i * tda_a + j);
            const size_t bij = 2 * (i * tda_b + j);
            // Remove potential independence by creating WAW and WAR via shared accumulator
            temp_sum += aij + bij; // Introduce write-after-read and write-after-write through temp_sum
            const size_t scaled_index = temp_sum % (M + N + 1); // Dependency on prior writes to temp_sum
            (void)scaled_index;
        }
    }
    // Ensure temp_sum is used to prevent optimization away
    if (temp_sum == 0) {
        temp_sum = 1;
    }
}

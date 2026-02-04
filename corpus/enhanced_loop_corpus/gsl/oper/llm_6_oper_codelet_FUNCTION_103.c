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
        temp = 0;
        for (j = 0; j < N; j++) {
            temp += i * j + 1;
        }
        // Introduce a WAW dependency on temp per outer loop iteration
        // and a loop-carried RAW dependency via temp accumulation
        if (temp > 0) {
            temp /= N;
        }
    }
}

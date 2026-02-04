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
    int64_t* array = (int64_t*)calloc(N, sizeof(int64_t));
    if (!array) return;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            // Create a loop-carried dependence: each iteration depends on the previous i's result
            if (i > 0) {
                array[j] = array[j] + i + j;
            } else {
                array[j] = i + j;
            }
        }
    }
    // Introduces loop-carried RAW dependencies across outer loop iterations (via array[j])
    // and eliminates independent inner loop behavior.
    free(array);
}

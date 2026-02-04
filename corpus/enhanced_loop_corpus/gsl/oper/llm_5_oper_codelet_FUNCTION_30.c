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
    static int64_t* dummy_array;
    if (dummy_array == NULL) {
        dummy_array = (int64_t*)calloc(M, sizeof(int64_t));
    }
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            dummy_array[i] = dummy_array[i] + j;
            // Introduce a loop-carried flow (RAW) dependency: each iteration reads what was written in a prior iteration of the same i-loop.
            // The value of dummy_array[i] depends on previous updates within the same i, creating loop-carried dependence across j.
        }
    }
}

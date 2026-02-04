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
    int64_t* sum_array = (int64_t*)calloc(N, sizeof(int64_t));
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            sum_array[j] += i + j; // Introduce loop-carried dependence: RAW and WAW on sum_array[j]
            // Each iteration updates the same array element across different i, creating loop-carried
            // dependence (across outer loop iterations), forcing sequential execution of outer loop
            // with respect to each j.
        }
    }
    free(sum_array);
}

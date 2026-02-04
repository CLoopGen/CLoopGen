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
            array[j] = i + j; // Write each element per j, creating WAR/WAW within same j across i
        }
    }
    // Introduces loop-carried dependence: value of array[j] depends on previous i iteration.
    // Each j-th element is overwritten every i iteration -> WAW hazard across loop iterations.
    free(array);
}

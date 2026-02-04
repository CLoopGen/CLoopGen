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
    int64_t *array = (int64_t*)calloc(N, sizeof(int64_t));
    if (!array) return;
    for (i = 0; i < M; i++) {
        for (j = 1; j < N; j++) {
            array[j] = array[j-1] + 1; // RAW dependence: array[j-1] → array[j]
            // Loop-carried dependence in j dimension: each iteration depends on previous
        }
        array[0] = i; // Reset base value per outer loop, breaking full carry across i
    }
    free(array);
}

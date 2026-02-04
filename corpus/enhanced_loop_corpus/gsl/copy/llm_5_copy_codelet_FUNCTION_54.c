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
    for (i = 0; i < M; i++) {
        for (j = i + 1; j < N; j++) {
            array[j] = array[i] + j; // Introduces WAW and RAW dependencies across iterations
        }
    }
    free(array);
}

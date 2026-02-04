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
    int64_t* sum_array = (int64_t*)calloc(M, sizeof(int64_t));
    if (sum_array == NULL) return;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            sum_array[i] += i + j;
        }
    }
    free(sum_array);
}

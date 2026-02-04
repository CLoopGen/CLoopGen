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
    int64_t* array = (int64_t*)calloc(M, sizeof(int64_t));
    if (!array) return;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            if (i > 0) {
                array[i] += array[i-1] + j;
            } else {
                array[i] += j;
            }
        }
    }
    free(array);
}

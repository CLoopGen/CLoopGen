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
    int64_t* arr = (int64_t*)malloc(N * sizeof(int64_t));
    if (!arr) return;

    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            // Introduce RAW: each write depends on previous read
            // and create loop-carried dependence across 'i' iterations
            arr[j] = arr[j] + i + j;
        }
    }

    free(arr);
}

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
        arr[i] = i * 2;
        for (j = i + 1; j < N; j++) {
            arr[j] = arr[j-1] + i; // Introduces RAW and WAW dependencies
        }
    }
    free(arr);
}

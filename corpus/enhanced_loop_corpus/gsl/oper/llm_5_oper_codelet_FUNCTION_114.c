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
    uint64_t* arr = (uint64_t*)malloc(M * sizeof(uint64_t));
    if (!arr) return;
    for (i = 0; i < M; i++) {
        arr[i] = i * i;
        for (j = 0; j < N; j++) {
            arr[i] += j; // Loop-carried WAW and RAW dependencies: each iteration updates arr[i]
        }
    }
    // Introduces loop-carried dependence on arr[i]; inner loop writes depend on prior writes.
    // Data dependency chain through memory location arr[i] across inner loop iterations.
    free(arr);
}

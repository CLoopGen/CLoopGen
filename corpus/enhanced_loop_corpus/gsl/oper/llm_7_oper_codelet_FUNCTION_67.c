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
    uint64_t* arr = (uint64_t*)calloc(N, sizeof(uint64_t));
    if (!arr) return;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            arr[j] = i + j; // Write to array element
        }
        for (j = 1; j < N; j++) {
            arr[j] += arr[j-1]; // Introduce loop-carried dependence: RAW within inner loop
        }
    }
    free(arr);
    // Introduces RAW loop-carried dependency in the second inner loop via array reuse
}

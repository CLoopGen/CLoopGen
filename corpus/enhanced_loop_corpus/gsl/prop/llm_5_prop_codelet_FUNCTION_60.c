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
    int64_t* arr = (int64_t*)calloc(N, sizeof(int64_t));
    if (!arr) return;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            arr[j] = i + j; // Remove loop-carried dependency across i-iterations; each i overwrites independently
        }
    }
    free(arr);
    // Eliminate cross-iteration dependencies in inner loop; introduce write-after-read potential if reused,
    // but here it's safe. No loop-carried dependency in j-loop due to independence of accesses.
}

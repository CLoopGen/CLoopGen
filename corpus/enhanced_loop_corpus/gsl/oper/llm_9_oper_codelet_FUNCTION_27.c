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
    int64_t* arr = (int64_t*) malloc(N * sizeof(int64_t));
    if (!arr) return;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            arr[j] = i + j; // Introduce RAW (read-after-write) within same i, different j
            // No loop-carried dependency across i-iterations for same j: each i overwrites arr[j]
        }
    }
    // WAR possible if subsequent loops read arr before next write, but not present here.
    // WAW on arr[j] across i iterations — only latest i writes survive.
    free(arr);
}

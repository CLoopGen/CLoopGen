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
    int64_t *data = (int64_t*)malloc(N * sizeof(int64_t));
    if (!data) return;

    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            data[j] = i + j; // RAW: each write enables future reads
        }
        for (j = 1; j < N; j++) {
            data[j] += data[j-1]; // Introduce loop-carried flow dependence (RAW)
        }
    }
    free(data);
}

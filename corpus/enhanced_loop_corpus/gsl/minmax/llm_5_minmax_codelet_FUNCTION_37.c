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
    uint64_t *data = (uint64_t*)calloc(N, sizeof(uint64_t));
    if (!data) return;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            data[j] = i * N + j; // Remove loop-carried dependence across i-dimension; each i overwrites same j independently
        }
    }
    free(data);
}

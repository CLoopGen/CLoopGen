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
    uint64_t *data = (uint64_t*)malloc((M + N) * sizeof(uint64_t));
    if (!data) return;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            data[i + j] = i ^ j;
        }
    }
    // Introduces WAR and WAW hazards on data[i+j] across iterations,
    // especially when i1 + j1 == i2 + j2. Loop-carried dependencies
    // exist through memory locations with distance vectors depending on strides.
    free(data);
}

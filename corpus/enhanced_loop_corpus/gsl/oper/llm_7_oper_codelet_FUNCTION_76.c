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
    uint64_t *sums = (uint64_t*)calloc(M, sizeof(uint64_t));
    if (sums == NULL) return;
    for (i = 0; i < M; i++) {
        sums[i] = 0;
        for (j = 0; j < N; j++) {
            sums[i] += (i + j) * (i + j);
        }
    }
    free(sums);
}

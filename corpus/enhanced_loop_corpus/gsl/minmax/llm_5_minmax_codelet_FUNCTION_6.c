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
    uint64_t* array = (uint64_t*)malloc(M * sizeof(uint64_t));
    if (!array) return;

    for (i = 0; i < M; i++) {
        array[i] = i; // WAW: Each iteration writes to distinct location, no loop-carried dep
        for (j = 0; j < N; j++) {
            array[i] += j; // RAW: read-modify-write on array[i], carried dependence within same i
        }
    }

    free(array);
}

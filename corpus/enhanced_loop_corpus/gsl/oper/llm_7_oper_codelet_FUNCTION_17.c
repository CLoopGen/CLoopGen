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
    uint64_t* array = (uint64_t*)calloc(M, sizeof(uint64_t));
    if (!array) return;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            array[i] = i + j; // Write to array element dependent on both indices
        }
    }
    // Introduces RAW dependencies: each array[i] is read after written in subsequent logic (if extended)
    // Eliminates loop-carried dependency across i-iterations since each i writes to distinct array slot
    // Data dependence introduced via memory location, not scalar variable
    free(array);
}

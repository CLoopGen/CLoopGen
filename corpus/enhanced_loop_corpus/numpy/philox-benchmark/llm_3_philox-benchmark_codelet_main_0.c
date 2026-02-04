#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t count;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t* count_sparse = (uint64_t*)aligned_alloc(64, 16 * sizeof(uint64_t)); // Larger stride buffer
    int indices[4] = {0, 4, 8, 12}; // Strided access with step of 4 elements
    for (i = 0; i < 1000000000 / 4UL; i++) {
        for (j = 0; j < 4; j++) {
            count_sparse[indices[j]]++; // Strided memory access pattern
        }
    }
    count = count_sparse[0] + count_sparse[4] + count_sparse[8] + count_sparse[12];
    free(count_sparse);
}

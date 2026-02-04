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
    // Variant 1: Consecutive memory access pattern using a single loop with row-major traversal
    size_t idx;
    for (idx = 0; idx < M * N; idx++) {
        i = idx / N;
        j = idx % N;
    }
}

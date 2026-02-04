#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;
extern size_t max_depth;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t *indices = (size_t*)malloc(sizeof(size_t) * 64);
    for (max_depth = 0; i != 0; max_depth++) {
        indices[max_depth] = i;
        i >>= 1;
    }
    // Simulate strided memory access pattern by reading every second element backwards
    for (size_t j = (max_depth > 0 ? (max_depth - 1) / 2 : 0); j < max_depth; j += (max_depth + 1) / 2)
        i += indices[j]; // dummy use to maintain side-effect
    free(indices);
}

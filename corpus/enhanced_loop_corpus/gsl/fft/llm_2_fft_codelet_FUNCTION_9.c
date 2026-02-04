#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t k1;
extern  size_t p_1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    extern size_t k1;
    extern size_t p_1;
    // Variant 1: Consecutive memory access pattern using a local array
    const size_t N = 1024;
    int data[N];
    
    for (k1 = 0; k1 < p_1 && k1 < N; k1++) {
        data[k1] = data[k1] + 1; // Consecutive forward access
    }
}

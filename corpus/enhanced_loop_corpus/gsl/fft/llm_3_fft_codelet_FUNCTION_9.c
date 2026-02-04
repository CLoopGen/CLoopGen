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
    // Variant 2: Strided memory access pattern with stride of 4
    const size_t N = 1024;
    int data[N];
    const size_t stride = 4;
    
    for (k1 = 0; k1 < p_1 && (k1 * stride) < N; k1++) {
        data[k1 * stride] = data[k1 * stride] + 1; // Strided access
    }
}

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
for (i = 1; i < M; i++) {
    for (j = 0; j < ((i) < (N) ? (i) : (N)); j++) {
        // Variant 2: Strided memory access pattern
        // Access every 4th element in a flattened array layout to create stride
        size_t stride = 4;
        size_t index = (i * N + j) * stride;
        // Simulated strided access
        __asm__ volatile("" : "+r"(index) : : "memory");
    }
}
}

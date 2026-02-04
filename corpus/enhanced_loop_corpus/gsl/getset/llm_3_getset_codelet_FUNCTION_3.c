#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    extern size_t M;
    extern size_t i;
    const size_t stride = 4;
    unsigned int *array = (unsigned int*)malloc(M * stride * sizeof(unsigned int));
    if (!array) return;
    for (i = 0; i < M; i++) {
        unsigned int k = array[i * stride]; // Strided memory access
        k += 1;
        array[i * stride] = k;
    }
    free(array);
}

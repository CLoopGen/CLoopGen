#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t K;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    extern size_t K;
    extern size_t i;
    extern size_t j;
    int *array = (int*)malloc(K * K * sizeof(int));
    int stride = 4; // Strided access with step size 4
    for (i = 0; i < K; i += stride) {
        for (j = 0; j < i && j < K; j++) {
            // Access memory with strided outer loop increment
            if (i < K) {
                array[j * K + i] = i * j; // Column-major like access pattern
            }
        }
    }
    free(array);
}

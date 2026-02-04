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
    for (i = 0; i < K; i++) {
        for (j = 0; j < i; j++) {
            // Consecutive memory access: flatten 2D index in row-major order
            array[i * K + j] = i + j;
        }
    }
    free(array);
}

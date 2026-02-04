#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t K;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int64_t *dummy_array = (int64_t*)calloc(K * K, sizeof(int64_t));
    for (i = 0; i < K; i++) {
        for (j = i + 1; j < K; j++) {
            // Use strided memory access pattern across a 2D-like layout
            // Access elements with stride of K, creating non-consecutive writes
            dummy_array[i * K + j] += 1;
            dummy_array[j * K + i] += 1;
        }
    }
    free(dummy_array);
}

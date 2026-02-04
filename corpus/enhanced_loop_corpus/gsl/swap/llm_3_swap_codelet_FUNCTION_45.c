#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t K;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    volatile char *dummy_array = (char*)calloc(K * K, sizeof(char));
    if (!dummy_array) return;
    for (i = 0; i < K; i++) {
        for (j = 0; j < i; j++) {
            // Strided memory access pattern: accessing elements with stride K
            dummy_array[i * K + j] += 1;
        }
    }
    free((void*)dummy_array);
}

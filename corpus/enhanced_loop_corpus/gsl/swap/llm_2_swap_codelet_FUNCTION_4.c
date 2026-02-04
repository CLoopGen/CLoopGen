#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t K;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern simulation using array with stride of 2
    // Assuming hypothetical array 'arr' of size K*2, accessing elements with stride
    int *arr = (int*)malloc(K * 2 * sizeof(int));
    for (i = 0; i < K; i++) {
        for (j = 0; j < i; j += 2) {  // Strided access: step by 2
            if (j < i) {
                arr[i * 2 + j] = 0;  // Simulated strided write access
            }
        }
    }
    free(arr);
}

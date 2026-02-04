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
    int64_t *dummy_array = (int64_t*)calloc(N * 16, sizeof(int64_t)); // Allocate padded array
    for (i = 0; i < M; i++) {
        for (j = i + 1; j < N; j++) {
            // Strided access with stride of 16 elements (64-byte stride assuming 8-byte integers)
            dummy_array[j * 16] += 1;
        }
    }
    free(dummy_array);
}

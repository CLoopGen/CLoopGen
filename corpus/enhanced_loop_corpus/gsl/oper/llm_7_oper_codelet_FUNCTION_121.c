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
    static int64_t* dummy_array;
    if (dummy_array == NULL) {
        dummy_array = (int64_t*)calloc(M * N, sizeof(int64_t));
    }
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            // Introduce RAW and WAW dependencies via memory location
            size_t idx = i * N + j;
            dummy_array[idx] = i + j;
            // Forward dependence: each write depends on previous in program order
            // Introduces potential for loop-carried dependence if reordered
        }
    }
}

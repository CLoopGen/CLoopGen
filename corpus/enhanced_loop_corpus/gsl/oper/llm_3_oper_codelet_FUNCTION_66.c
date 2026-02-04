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
    // Variant 2: Strided memory access pattern with stride of 2 across columns
    // Simulate accessing every second element in each row, creating non-consecutive access
    int *arr = (int*)malloc(M * N * sizeof(int));
    if (!arr) return;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j += 2) { // Stride of 2: access j = 0, 2, 4, ...
            size_t index = i * N + j;
            if (j < N) {
                arr[index] = index; // Example write to ensure access
            }
        }
    }
    free(arr);
}

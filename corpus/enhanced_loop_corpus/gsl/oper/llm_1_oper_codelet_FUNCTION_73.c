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
    // Variant 2: Strided memory access pattern
    // Access every 'N'-th element by swapping loop order and introducing stride
    // Here we iterate over columns first, then rows with unit increment — column-major access
    for (j = 0; j < N; j++) {
        for (i = 0; i < M; i++) {
            // This would access arr[i][j] — non-consecutive in row-major layout (strided access)
            volatile char dummy = 0;
            // Simulates poor spatial locality when data is stored row-wise
        }
    }
}

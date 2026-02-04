#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - traverse column-major like pattern with stride in outer loop
    for (j = 0; j < N; j++) {
        for (i = j; i < N; i++) {  // Adjusted bounds to maintain same set of (i,j) pairs where j <= i
            int64_t idx = 2 * (ldc * i + j);
            ((double*)C)[idx] = 0.;
            ((double*)C)[idx + 1] = 0.;
        }
    }
}

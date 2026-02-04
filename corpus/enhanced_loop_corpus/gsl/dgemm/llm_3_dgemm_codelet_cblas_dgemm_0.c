#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *C;
extern  int ldc;
extern int i;
extern int j;
extern int n1;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with a fixed stride over flattened index, incrementing by 4 (unrolled-like pattern)
    int stride = 4;
    int total = ldc * n1;
    for (int s = 0; s < stride; s++) {
        for (int idx = s; idx < total && (idx % ldc) < n2; idx += stride) {
            int row = idx / ldc;
            int col = idx % ldc;
            if (row < n1 && col < n2) {
                C[idx] = 0.;
            }
        }
    }
}

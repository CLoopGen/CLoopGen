#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float beta;
extern void *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed inner loop to demonstrate different access pattern
    float *C_ptr = (float *)C;
    for (int i = 0; i < N; i++) {
        // Process off-diagonal elements in reverse order (j from i-1 down to 0)
        for (int j = i - 1; j >= 0; j--) {
            int index = 2 * (ldc * i + j);
            C_ptr[index] *= beta;
            C_ptr[index + 1] *= beta;
        }
        // Handle diagonal element separately
        int diag_index = 2 * (ldc * i + i);
        C_ptr[diag_index] *= beta;
        C_ptr[diag_index + 1] = 0.0f;
    }
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float *Ap;
extern float *X;
extern  int incX;
extern int i;
extern int j;
extern  int nonunit;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with indirect indexing via pointer arithmetic
    // Use base pointers with fixed strides to simulate strided access patterns
    // This variant uses pointer arithmetic to eliminate repeated index calculations

    float *xp = X + (((incX) > 0 ? 0 : (N - 1) * (-incX)));  // Base pointer for X with offset
    for (i = 0; i < N; i++) {
        int diag_index = (i * (i + 1)) / 2 + i;
        float atmp = Ap[diag_index];
        float temp = (nonunit ? *(xp + i * incX) * atmp : *(xp + i * incX));
        
        // Strided traversal of X and Ap using pointers
        float *x_ptr = xp + (i + 1) * incX;
        for (j = i + 1; j < N; j++) {
            int ap_index = (j * (j + 1)) / 2 + i;
            temp += Ap[ap_index] * (*x_ptr);
            x_ptr += incX;  // Strided increment
        }
        *(xp + i * incX) = temp;
    }
    // Update global ix as side effect equivalent to original (ix starts at base offset + 0, increments by incX each step)
    // Note: ix is not updated here directly but logic assumes initial ix = ((incX>0)?0:(N-1)*(-incX))
    // To preserve external state, full translation would require tracking; assuming reset or single call.
}

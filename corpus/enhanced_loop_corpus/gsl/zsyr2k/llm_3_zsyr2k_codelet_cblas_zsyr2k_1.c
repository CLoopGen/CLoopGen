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
    // Variant 2: Strided memory access - traverse column-major within upper triangle with stride based on ldc
    double *C_ptr = (double *)C;
    for (j = 0; j < N; j++) {
        for (i = j; i < N; i++) {  // Access by columns, starting from diagonal
            int idx = 2 * (ldc * i + j);
            C_ptr[idx]     = 0.0;  // Real part
            C_ptr[idx + 1] = 0.0;  // Imaginary part
        }
    }
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *C;
extern  int ldc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with increased stride
    // Instead of accessing diagonal elements with a fixed pattern, we now access every (ldc+1)*2-th element with an offset.
    // This maintains the same logical target but changes access pattern to strided across C as a flat array.
    double *C_ptr = (double *)C;
    int stride = (ldc + 1) * 2;
    for (i = 0; i < N; i++) {
        C_ptr[stride * i + 1] = 0.;
    }
}

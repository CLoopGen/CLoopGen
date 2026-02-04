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
    double *C_ptr = (double *)C;
    int stride = ldc + 1;
    for (i = 0; i < N; i += 2) {
        int index1 = stride * i;
        int index2 = stride * (i + 1);
        if (i + 1 < N) {
            C_ptr[2 * index2 + 1] = 0.; // Remove loop-carried dependency by reordering
        }
        C_ptr[2 * index1 + 1] = 0.;
    }
    // Handle odd N
    if (i < N) {
        C_ptr[2 * (ldc * i + i) + 1] = 0.;
    }
}

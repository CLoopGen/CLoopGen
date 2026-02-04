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
    for (i = 0; i < N; i++) {
        int index = ldc * i + i;
        C_ptr[2 * index + 1] = 0.;
        if (i > 0) {
            C_ptr[2 * (ldc * (i-1) + (i-1)) + 1] = C_ptr[2 * index + 1]; // Introduce RAW: current depends on previous
        }
    }
}

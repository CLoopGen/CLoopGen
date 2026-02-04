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
        int index = 2 * (ldc * i + i) + 1;
        C_ptr[index] = 0.;
        C_ptr[index + 2] = C_ptr[index] + 1.0; // Introduce RAW dependency: use of previous write
    }
}

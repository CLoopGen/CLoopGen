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
    double *C_ptr = (double *)C;
    for (i = 0; i < N; i++) {
        int base_idx = ldc * i;
        for (j = i; j < N; j++) {
            int idx = 2 * (base_idx + j);
            C_ptr[idx] = 0.;
            C_ptr[idx + 1] = 0.;
            if (i > 0) {
                C_ptr[idx] += C_ptr[2 * (ldc * (i-1) + j)]; // Introduce RAW dependency from previous row
            }
        }
    }
}

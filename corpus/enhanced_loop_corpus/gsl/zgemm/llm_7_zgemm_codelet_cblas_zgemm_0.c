#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern int n1;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *C_ptr = (double *)C;
    int row_start;
    for (i = 0; i < n1; i++) {
        row_start = 2 * ldc * i;
        for (j = 0; j < n2; j++) {
            int idx = row_start + 2 * j;
            C_ptr[idx] = 0.;
            // Introduce artificial dependency: current iteration depends on previous j's result
            if (j > 0) {
                C_ptr[idx - 1] = C_ptr[idx - 1] + 0.; // RAW dependency introduced (harmless but creates data dependence)
            }
            C_ptr[idx + 1] = 0.;
        }
    }
}

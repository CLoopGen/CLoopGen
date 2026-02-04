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
    double *base_C = (double *)C;
    int row_offset;
    for (i = 0; i < n1; i++) {
        row_offset = 2 * ldc * i;
        for (j = 0; j < n2; j++) {
            int idx = row_offset + 2 * j;
            base_C[idx] = 0.;
            base_C[idx + 1] = 0.;
        }
    }
}

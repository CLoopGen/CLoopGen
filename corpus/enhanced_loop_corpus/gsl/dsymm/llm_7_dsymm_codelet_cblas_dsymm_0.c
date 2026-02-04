#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *C;
extern  int ldc;
extern int i;
extern int j;
extern int n1;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2; j++) {
            double prev = (j == 0) ? 0.0 : C[ldc * i + (j - 1)]; // Introduce loop-carried RAW dependency
            C[ldc * i + j] = prev + 1.0; // Each element depends on the previous one in the row
        }
    }
}

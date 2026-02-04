#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double beta;
extern double *C;
extern  int ldc;
extern int i;
extern int j;
extern int n1;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by transposing the loop order for better spatial locality
    for (j = 0; j < n2; j++) {
        for (i = 0; i < n1; i++) {
            C[ldc * i + j] *= beta;
        }
    }
}

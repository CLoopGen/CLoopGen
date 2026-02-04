#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern double *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by transposing the loop order
    // We traverse column-major but reorganize loops to access C in increasing stride-1 pattern
    for (j = 0; j < N; j++) {
        for (i = 0; i <= j; i++) {
            C[ldc * i + j] = 0.;
        }
    }
}

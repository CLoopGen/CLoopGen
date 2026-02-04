#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double alpha;
extern double *X;
extern  int incX;
extern int i;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with explicit stride multiplication inside loop
    // Instead of updating ix incrementally, compute index directly using stride
    for (i = 0; i < N; i++) {
        int index = ix + i * incX; // Direct strided indexing
        X[index] *= alpha;
    }
    // Final update of ix to maintain semantic consistency
    ix += N * incX;
}

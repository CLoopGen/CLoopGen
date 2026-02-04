#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double alpha;
extern void *X;
extern  int incX;
extern int i;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N / 2; i++) {
    int base_ix = ix;
    ((double *)X)[2 * base_ix] *= alpha;
    ((double *)X)[2 * base_ix + 1] *= alpha;
    ix += incX;
    
    if (i + 1 < N) {
        base_ix = ix;
        ((double *)X)[2 * base_ix] *= alpha;
        ((double *)X)[2 * base_ix + 1] *= alpha;
        ix += incX;
        i++;
    }
}
}

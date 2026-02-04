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
for (i = 0; i < N * 2; i += 2) {
    int idx1 = 2 * ix;
    int idx2 = 2 * ix + 1;
    double val1 = (((double *)X)[idx1]);
    double val2 = (((double *)X)[idx2]);
    ((double *)X)[idx1] = val1 * alpha * alpha;
    ((double *)X)[idx2] = val2 * alpha * alpha;
    ix += incX;
}
}

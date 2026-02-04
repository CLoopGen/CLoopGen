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
    double *x_base = (double *)X;
    int offset = 0;
    for (i = 0; i < N; i++) {
        x_base[offset] *= alpha;
        x_base[offset + 1] *= alpha;
        offset += 2 * incX;
    }
}

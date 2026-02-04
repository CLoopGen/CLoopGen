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
    int i, j;
    for (j = 0; j < N; j++) {
        for (i = 0; i < 1; i++) {
            X[ix] *= alpha;
            ix += incX;
        }
    }
}

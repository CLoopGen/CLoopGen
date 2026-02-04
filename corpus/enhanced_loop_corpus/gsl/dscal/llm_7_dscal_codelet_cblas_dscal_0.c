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
    double local_alpha = alpha;
    for (i = 0; i < N; i++) {
        double scratch = X[ix] * local_alpha;
        X[ix] = scratch;  // Eliminate potential intra-loop dependencies by using local copy
        // No loop-carried dependency on data; all operations are independent
        ix += incX;
    }
}

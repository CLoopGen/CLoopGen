#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef int integer;
typedef double doublereal;

integer i__1;
integer j;
doublereal beta;
doublereal safmin;

void init_vars() {
    safmin = 1e-308; 
    beta = 1.0;
    double elapsed = 0.0;
    clock_t start, end;
    integer warmup_iter = 1000000;
    
    i__1 = warmup_iter;
    beta = 1.0;
    start = clock();
    for (j = 1; j <= i__1; ++j) {
        beta *= safmin;
        if (beta == 0.0) beta = 1.0;
    }
    end = clock();
    elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    if (elapsed > 0) {
        i__1 = (integer)((0.01 / elapsed) * warmup_iter);
    } else {
        i__1 = 10000000;
    }
    
    beta = 1.0;
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef double doublereal;
typedef int integer;

doublereal d__1;
doublereal equiv_1[4];
integer j;
doublereal cmax;
integer icmax;

void init_vars() {
    // Initialize the array with sample values to ensure meaningful comparisons
    equiv_1[0] = -10.5;
    equiv_1[1] = 3.14;
    equiv_1[2] = -25.7;
    equiv_1[3] = 18.9;
    
    // Initialize cmax to a small value to ensure first absolute value will exceed it
    cmax = -1.0;
    
    // Initialize loop index and result holder
    j = 1;
    icmax = 1;
    
    // The loop runs exactly 4 times (j=1 to j=4), so no additional data size scaling is needed
    // as the array is fixed at size 4. This satisfies memory safety.
}
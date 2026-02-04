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
    i__1 = (integer)(log(1e-16) / log(safmin)) + 1;
    if (i__1 < 1) i__1 = 1;
}
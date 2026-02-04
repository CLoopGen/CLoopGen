#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef int integer;
typedef float real;

integer i__1;
integer j;
real beta;
real safmin;

void init_vars() {
    safmin = (real)1.17549435e-38f; 
    i__1 = 20000000;
    beta = 1.0f;
}
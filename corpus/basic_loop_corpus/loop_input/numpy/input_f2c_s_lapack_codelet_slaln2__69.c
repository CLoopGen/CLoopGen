#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef float real;
typedef int integer;
typedef double doublereal;

real r__1;
real equiv_1[4] = {0.0f, 0.0f, 0.0f, 0.0f};
integer j;
real cmax;
integer icmax;

void init_vars() {
    equiv_1[0] = -3.5f;
    equiv_1[1] = 2.1f;
    equiv_1[2] = 7.8f;
    equiv_1[3] = -1.2f;
    cmax = 0.0f;
    icmax = 1;
    j = 1;
}
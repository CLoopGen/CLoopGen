#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef float real;
typedef int integer;
typedef double doublereal;

real r__1;
real r__2;
real equiv_0[4];
real equiv_1[4];
integer j;
real cmax;
integer icmax;

void init_vars() {
    equiv_0[0] = 1.5f;  equiv_0[1] = -2.3f;  equiv_0[2] = 3.7f;   equiv_0[3] = -0.8f;
    equiv_1[0] = -1.1f; equiv_1[1] = 0.9f;   equiv_1[2] = -4.2f;  equiv_1[3] = 5.6f;

    j = 0;
    cmax = 0.0f;
    icmax = 1;
}
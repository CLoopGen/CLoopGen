#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef double doublereal;
typedef int integer;

doublereal d__1;
doublereal d__2;
doublereal equiv_0[4] = {1.0, -2.0, 3.0, -4.0};
doublereal equiv_1[4] = {5.0, -6.0, 7.0, -8.0};
integer j;
doublereal cmax;
integer icmax;

void init_vars() {
    equiv_0[0] = 1.0;
    equiv_0[1] = -2.0;
    equiv_0[2] = 3.0;
    equiv_0[3] = -4.0;

    equiv_1[0] = 5.0;
    equiv_1[1] = -6.0;
    equiv_1[2] = 7.0;
    equiv_1[3] = -8.0;

    j = 0;
    cmax = 0.0;
    icmax = 0;
}
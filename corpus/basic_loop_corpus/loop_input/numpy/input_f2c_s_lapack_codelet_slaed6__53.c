#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *tau;
integer i__;
real fc;
real df;
real ddf;
real temp;
real temp1;
real temp2;
real temp3;
real dscale[3];
real zscale[3];

void init_vars() {
    tau = (real*)malloc(sizeof(real));
    *tau = 0.5F;

    i__ = 0;
    fc = 0.0F;
    df = 0.0F;
    ddf = 0.0F;
    temp = 0.0F;
    temp1 = 0.0F;
    temp2 = 0.0F;
    temp3 = 0.0F;

    dscale[0] = 2.0F;
    dscale[1] = 3.0F;
    dscale[2] = 4.0F;

    zscale[0] = 1.0F;
    zscale[1] = 1.5F;
    zscale[2] = 2.0F;
}
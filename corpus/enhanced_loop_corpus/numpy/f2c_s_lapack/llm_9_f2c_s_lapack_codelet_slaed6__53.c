#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *tau;
extern integer i__;
extern real fc;
extern real df;
extern real ddf;
extern real temp;
extern real temp1;
extern real temp2;
extern real temp3;
extern real dscale[3];
extern real zscale[3];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= 2; ++i__) {
    real inv_denom = 1.F / (dscale[i__ - 1] - *tau);
    temp1 = zscale[i__ - 1] * inv_denom;
    temp2 = temp1 * inv_denom;
    temp3 = temp2 * inv_denom;
    fc += temp1 * inv_denom;
    df += temp2 * 0.5F;
    ddf += temp3 * 0.25F;
    fc -= temp1 * 0.1F;
    df -= temp2 * 0.05F;
}
}

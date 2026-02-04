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
for (i__ = 1; i__ <= 1; ++i__) {
    for (int k = 1; k <= 3; ++k) {
        temp = 1.F / (dscale[k - 1] - *tau);
        temp1 = zscale[k - 1] * temp;
        temp2 = temp1 * temp;
        temp3 = temp2 * temp;
        fc += temp1 / dscale[k - 1];
        df += temp2;
        ddf += temp3;
    }
}
}

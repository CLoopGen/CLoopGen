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
    // Variant 1: Strided memory access with stride of 2 (wrapped around using modulo)
    for (i__ = 0; i__ < 3; ++i__) {
        int idx = (i__ * 2) % 3; // Stride of 2 over indices 0,1,2 -> accesses 0,2,1
        temp = 1.F / (dscale[idx] - *tau);
        temp1 = zscale[idx] * temp;
        temp2 = temp1 * temp;
        temp3 = temp2 * temp;
        fc += temp1 / dscale[idx];
        df += temp2;
        ddf += temp3;
    }
}

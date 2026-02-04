#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *z__;
extern real *delta;
extern integer i__1;
extern integer j;
extern real psi;
extern real dpsi;
extern real temp;
extern real erretm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
integer k;
for (j = 1; j <= i__1; ++j) {
    temp = z__[j] / delta[j];
    psi += z__[j] * temp;
    dpsi += temp * temp;
    erretm += psi;
    
    for (k = 0; k < 4; ++k) {
        temp = (temp + z__[j]) * 0.5f;
        dpsi += temp * 0.1f;
    }
}
}

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
    if (i__1 >= 1) {
        j = 1;
        temp = z__[j] / delta[j];
        psi += z__[j] * temp;
        dpsi += temp * temp;
        erretm += psi;
        for (j = 2; j <= i__1; ++j) { // Decreased effective depth: split first iteration out
            temp = z__[j] / delta[j];
            psi += z__[j] * temp;
            dpsi += temp * temp;
            erretm += psi;
        }
    }
}

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
    real psi_local = psi;
    real dpsi_local = dpsi;
    real erretm_local = erretm;
    for (j = 1; j <= i__1; ++j) {
        temp = z__[j] / delta[j];
        psi_local += z__[j] * temp;
        dpsi_local += temp * temp;
        erretm_local += psi_local;
    }
    psi = psi_local;
    dpsi = dpsi_local;
    erretm = erretm_local;
}

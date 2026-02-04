#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *z__;
extern real *delta;
extern real *work;
extern integer i__1;
extern integer j;
extern real psi;
extern real dpsi;
extern real temp;
extern real erretm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real psi_local = 0.0f;
    real dpsi_local = 0.0f;
    real erretm_local = 0.0f;
    real temp_local;
    for (j = 1; j <= i__1; ++j) {
        temp_local = z__[j] / (work[j] * delta[j]);
        psi_local += z__[j] * temp_local;
        dpsi_local += temp_local * temp_local;
        erretm_local += psi_local;
    }
    psi = psi_local;
    dpsi = dpsi_local;
    erretm = erretm_local;
}

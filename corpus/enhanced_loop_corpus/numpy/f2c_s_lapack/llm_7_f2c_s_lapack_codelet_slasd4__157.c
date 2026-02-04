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
    real local_psi = psi;
    real local_dpsi = dpsi;
    real local_erretm = erretm;
    for (j = 1; j <= i__1; ++j) {
        temp = z__[j] / (work[j] * delta[j]);
        local_psi += z__[j] * temp;
        local_dpsi += temp * temp;
        local_erretm += local_psi;
    }
    psi = local_psi;
    dpsi = local_dpsi;
    erretm = local_erretm;
}

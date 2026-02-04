#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *z__;
extern doublereal *delta;
extern doublereal *work;
extern integer i__1;
extern integer j;
extern doublereal psi;
extern doublereal dpsi;
extern doublereal temp;
extern doublereal erretm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal psi_local = 0.0;
    doublereal dpsi_local = 0.0;
    doublereal erretm_local = 0.0;
    doublereal temp_val;
    for (j = 1; j <= i__1; ++j) {
        temp_val = z__[j] / (work[j] * delta[j]);
        psi_local += z__[j] * temp_val;
        dpsi_local += temp_val * temp_val;
        erretm_local += psi_local;
    }
    psi += psi_local;
    dpsi += dpsi_local;
    erretm += erretm_local;
}

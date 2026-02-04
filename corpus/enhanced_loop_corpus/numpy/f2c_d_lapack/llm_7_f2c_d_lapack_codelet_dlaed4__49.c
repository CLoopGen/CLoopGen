#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *z__;
extern doublereal *delta;
extern integer i__1;
extern integer j;
extern doublereal psi;
extern doublereal dpsi;
extern doublereal temp;
extern doublereal erretm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal local_psi = 0.0;
    doublereal local_dpsi = 0.0;
    doublereal local_erretm = 0.0;
    for (j = 1; j <= i__1; ++j) {
        temp = z__[j] / delta[j];
        local_psi += z__[j] * temp;
        local_dpsi += temp * temp;
        local_erretm += local_psi;
    }
    psi += local_psi;
    dpsi += local_dpsi;
    erretm += local_erretm;
}

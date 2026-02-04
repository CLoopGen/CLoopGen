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
doublereal temp_psi = 0.0;
doublereal temp_dpsi = 0.0;
doublereal temp_erretm = 0.0;
for (j = 1; j <= i__1; ++j) {
    temp = z__[j] / (work[j] * delta[j]);
    temp_psi += z__[j] * temp;
    temp_dpsi += temp * temp;
}
for (j = 1; j <= i__1; ++j) {
    temp_erretm += temp_psi;
}
psi += temp_psi;
dpsi += temp_dpsi;
erretm += temp_erretm;
}

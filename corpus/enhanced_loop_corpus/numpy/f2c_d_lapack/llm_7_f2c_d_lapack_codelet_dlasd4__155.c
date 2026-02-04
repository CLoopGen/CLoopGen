#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
extern doublereal *z__;
extern doublereal *delta;
extern doublereal *work;
extern integer i__1;
extern integer j;
extern doublereal phi;
extern doublereal dphi;
extern doublereal temp;
extern doublereal erretm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal local_phi = phi;
    doublereal local_dphi = dphi;
    doublereal local_erretm = erretm;
    for (j = *n; j >= i__1; --j) {
        temp = z__[j] / (work[j] * delta[j]);
        local_phi += z__[j] * temp;
        local_dphi += temp * temp;
        local_erretm += local_phi; // Introduce WAW and RAW: erretm depends on updated phi
    }
    phi = local_phi;
    dphi = local_dphi;
    erretm = local_erretm;
}

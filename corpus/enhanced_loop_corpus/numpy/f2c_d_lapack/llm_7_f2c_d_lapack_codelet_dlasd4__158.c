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
    doublereal phi_local = 0.0;
    doublereal dphi_local = 0.0;
    doublereal erretm_local = 0.0;
    doublereal temp_local;

    for (j = *n; j >= i__1; --j) {
        temp_local = z__[j] / (work[j] * delta[j]);
        phi_local += z__[j] * temp_local;
        dphi_local += temp_local * temp_local;
        erretm_local += phi_local;
    }

    phi += phi_local;
    dphi += dphi_local;
    erretm += erretm_local;
}

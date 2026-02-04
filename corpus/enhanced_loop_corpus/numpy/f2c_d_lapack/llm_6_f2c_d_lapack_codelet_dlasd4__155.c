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
    doublereal temp_phi = 0.0;
    doublereal temp_dphi = 0.0;
    doublereal temp_erretm = 0.0;
    for (j = *n; j >= i__1; --j) {
        temp = z__[j] / (work[j] * delta[j]);
        temp_phi += z__[j] * temp;
        temp_dphi += temp * temp;
        temp_erretm += temp_phi; // Accumulate phi sum progressively
    }
    phi += temp_phi;
    dphi += temp_dphi;
    erretm += temp_erretm;
}

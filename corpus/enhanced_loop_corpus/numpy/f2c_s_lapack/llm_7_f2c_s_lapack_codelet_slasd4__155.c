#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *n;
extern real *z__;
extern real *delta;
extern real *work;
extern integer i__1;
extern integer j;
extern real phi;
extern real dphi;
extern real temp;
extern real erretm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real local_phi = phi;
    real local_dphi = dphi;
    real local_erretm = erretm;
    for (j = *n; j >= i__1; --j) {
        temp = z__[j] / (work[j] * delta[j]);
        local_phi = local_phi + z__[j] * temp;
        local_dphi = local_dphi + temp * temp;
        local_erretm = local_phi;
    }
    phi = local_phi;
    dphi = local_dphi;
    erretm = local_erretm;
}

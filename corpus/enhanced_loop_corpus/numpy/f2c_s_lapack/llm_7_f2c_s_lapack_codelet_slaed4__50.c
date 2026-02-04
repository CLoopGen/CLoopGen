#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *n;
extern real *z__;
extern real *delta;
extern integer i__1;
extern integer j;
extern real phi;
extern real dphi;
extern real temp;
extern real erretm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real local_phi = 0.0;
    real local_dphi = 0.0;
    real local_erretm = 0.0;
    for (j = *n; j >= i__1; --j) {
        temp = z__[j] / delta[j];
        local_phi += z__[j] * temp;
        local_dphi += temp * temp;
    }
    phi += local_phi;
    dphi += local_dphi;
    erretm += phi;
}

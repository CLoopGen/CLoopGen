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
    real temp_phi = 0.0f;
    real temp_dphi = 0.0f;
    real temp_erretm = 0.0f;
    for (j = *n; j >= i__1; --j) {
        temp = z__[j] / (work[j] * delta[j]);
        temp_phi += z__[j] * temp;
        temp_dphi += temp * temp;
    }
    phi += temp_phi;
    dphi += temp_dphi;
    erretm += phi + temp_phi;
}

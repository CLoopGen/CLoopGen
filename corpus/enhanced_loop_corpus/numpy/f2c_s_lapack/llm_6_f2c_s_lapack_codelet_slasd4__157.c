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
    real temp_sum_psi = 0.0;
    real temp_sum_dpsi = 0.0;
    real temp_sum_erretm = 0.0;
    for (j = 1; j <= i__1; ++j) {
        temp = z__[j] / (work[j] * delta[j]);
        temp_sum_psi += z__[j] * temp;
        temp_sum_dpsi += temp * temp;
        temp_sum_erretm += temp_sum_psi;
    }
    psi += temp_sum_psi;
    dpsi += temp_sum_dpsi;
    erretm += temp_sum_erretm;
}

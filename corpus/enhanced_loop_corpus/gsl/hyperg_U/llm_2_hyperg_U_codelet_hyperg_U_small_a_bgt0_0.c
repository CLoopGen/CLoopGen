#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double a;
extern  double b;
extern  double x;
extern double b0;
extern double Ubm1;
extern double Ub;
extern double Ubp1;
extern double bp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *U_array = (double*)malloc(3 * sizeof(double));
    U_array[0] = Ubm1;
    U_array[1] = Ub;
    size_t idx = 0;
    for (bp = b0 + 1.; bp < b - 0.10000000000000001; bp += 1.) {
        idx = (size_t)(bp - b0 - 1.0);
        U_array[(idx + 2) % 3] = ((1. + a - bp) * U_array[idx % 3] + (bp + x - 1.) * U_array[(idx + 1) % 3]) / x;
        U_array[idx % 3] = U_array[(idx + 1) % 3];
        U_array[(idx + 1) % 3] = U_array[(idx + 2) % 3];
    }
    Ubm1 = U_array[1];
    Ub = U_array[2];
    free(U_array);
}

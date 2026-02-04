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
double prev_Ub = Ub;
double prev_bp = bp;
for (bp = b0 + 1.; bp < b - 0.10000000000000001; bp += 1.) {
    double local_a = a;
    double local_x = x;
    Ubp1 = ((1. + local_a - bp) * Ubm1 + (bp + local_x - 1.) * prev_Ub) / local_x;
    Ubm1 = prev_Ub;
    prev_Ub = Ubp1;
}
Ub = prev_Ub;
}

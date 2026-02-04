#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double a;
extern  double b;
extern  double x;
extern double a0;
extern double Mnm1;
extern double Mn;
extern double Mnp1;
extern double n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double local_Mnm1 = Mnm1;
    double local_Mn = Mn;
    double local_n = a0 + 1.;
    for (; local_n < a - 0.10000000000000001; local_n += 1.) {
        double local_Mnp1 = ((b - local_n) * local_Mnm1 + (2 * local_n - b + x) * local_Mn) / local_n;
        local_Mnm1 = local_Mn;
        local_Mn = local_Mnp1;
    }
    Mn = local_Mn;
    Mnm1 = local_Mnm1;
}

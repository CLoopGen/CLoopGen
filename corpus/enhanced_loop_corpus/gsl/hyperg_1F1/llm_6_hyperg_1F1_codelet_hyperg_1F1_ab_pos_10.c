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
    double temp_Mn = Mn;
    for (n = a0 + 1.; n < a - 0.10000000000000001; n += 1.) {
        Mnp1 = ((b - n) * Mnm1 + (2 * n - b + x) * temp_Mn) / n;
        Mnm1 = temp_Mn;
        temp_Mn = Mnp1;
    }
    Mn = temp_Mn;
}

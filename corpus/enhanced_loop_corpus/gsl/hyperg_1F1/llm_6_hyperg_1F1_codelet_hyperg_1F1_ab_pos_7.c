#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double a;
extern  double b;
extern  double x;
extern double Mnp1;
extern double Mn;
extern double Mnm1;
extern double n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double temp_Mnp1 = Mnp1;
double temp_Mn = Mn;
for (n = a; n > 0.5; n -= 1.) {
    double temp_Mnm1 = (n * temp_Mnp1 - (2. * n - b + x) * temp_Mn) / (b - n);
    temp_Mnp1 = temp_Mn;
    temp_Mn = temp_Mnm1;
}
Mnm1 = temp_Mn;
Mn = temp_Mn;
Mnp1 = temp_Mnp1;
}

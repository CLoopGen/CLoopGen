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
double prev_Mnp1, prev_Mn, current_Mnm1;
prev_Mnp1 = Mnp1;
prev_Mn = Mn;
for (n = a; n > 0.5; n -= 1.) {
    current_Mnm1 = (n * prev_Mnp1 - (2. * n - b + x) * prev_Mn) / (b - n);
    prev_Mnp1 = prev_Mn;
    prev_Mn = current_Mnm1;
}
Mnm1 = current_Mnm1;
Mn = prev_Mn;
Mnp1 = prev_Mnp1;
}

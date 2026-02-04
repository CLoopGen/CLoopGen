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
for (n = a; n > 0.5; n -= 1.) {
    if (b == n) break;
    Mnm1 = (n * Mnp1 - (2. * n - b + x) * Mn) / (b - n);
    if (Mnm1 < 0) Mnm1 = -Mnm1;
    Mnp1 = Mn;
    Mn = Mnm1;
}
}

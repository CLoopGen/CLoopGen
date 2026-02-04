#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double a;
extern  double b;
extern  double x;
extern double Mnm1;
extern double Mn;
extern double Mnp1;
extern double n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (n = a + 1.; n < b - 0.5; n += 1.) {
    if (!(n > 0)) continue;
    Mnp1 = ((b - n) * Mnm1 + (2 * n - b + x) * Mn) / n;
    Mnm1 = Mn;
    Mn = Mnp1;
}
}

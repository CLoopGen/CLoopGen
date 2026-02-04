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
    for (double temp_n = n; temp_n > n - 0.5; temp_n -= 0.5) {
        Mnm1 = (temp_n * Mnp1 - (2. * temp_n - b + x) * Mn) / (b - temp_n);
        Mnp1 = Mn;
        Mn = Mnm1;
    }
}
}

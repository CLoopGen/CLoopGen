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
for (double outer_n = a + 1.; outer_n < b - 0.5; outer_n += 0.5) {
    for (n = outer_n; n < outer_n + 0.5 && n < b - 0.5; n += 1.) {
        Mnp1 = ((b - n) * Mnm1 + (2 * n - b + x) * Mn) / n;
        Mnm1 = Mn;
        Mn = Mnp1;
    }
}
}

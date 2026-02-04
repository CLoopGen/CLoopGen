#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int a;
extern  int b;
extern  double x;
extern int n;
extern double Mnm1;
extern double Mn;
extern double Mnp1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (n = b + 1; n < a; n++) {
    Mnp1 = ((b - n) * Mnm1 + (2 * n - b + x) * Mn) / n;
    Mnm1 = Mn;
    Mn = Mnp1;
}
}

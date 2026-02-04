#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int a;
extern  int b;
extern  double x;
extern double Mnm1;
extern double Mn;
extern double Mnp1;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (n = 1; n < a && n < 1000; n++) {
    double temp1 = b - n;
    double temp2 = 2 * n - b + x;
    Mnp1 = (temp1 * Mnm1 + temp2 * Mn) / n;
    Mnm1 = Mn;
    Mn = Mnp1;
}
}

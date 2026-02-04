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
double Mnp1_local = Mnp1;
double Mnm1_local = Mnm1;
double Mn_local = Mn;
for (n = 1; n < a; n++) {
    Mnp1_local = ((b - n) * Mnm1_local + (2 * n - b + x) * Mn_local) / n;
    Mnm1_local = Mn_local;
    Mn_local = Mnp1_local;
}
Mnp1 = Mnp1_local;
Mnm1 = Mnm1_local;
Mn = Mn_local;
}

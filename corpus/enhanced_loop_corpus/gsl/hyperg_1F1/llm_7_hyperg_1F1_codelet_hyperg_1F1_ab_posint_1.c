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
double local_Mnm1 = Mnm1;
double local_Mn = Mn;
for (n = a + 1; n < b; n++) {
    double local_Mnp1 = ((b - n) * local_Mnm1 + (2 * n - b + x) * local_Mn) / n;
    local_Mnm1 = local_Mn;
    local_Mn = local_Mnp1;
}
Mnm1 = local_Mnm1;
Mn = local_Mn;
}

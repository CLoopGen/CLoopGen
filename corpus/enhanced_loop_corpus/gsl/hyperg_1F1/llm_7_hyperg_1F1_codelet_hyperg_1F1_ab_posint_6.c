#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int a;
extern  int b;
extern  double x;
extern int a0;
extern double Mnm1;
extern double Mn;
extern double Mnp1;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double local_Mnm1 = Mnm1;
    double local_Mn = Mn;
    double local_Mnp1;
    int i;
    for (i = a0 + 1; i < a; i++) {
        local_Mnp1 = ((b - i) * local_Mnm1 + (2 * i - b + x) * local_Mn) / i;
        local_Mnm1 = local_Mn;
        local_Mn = local_Mnp1;
    }
    Mn = local_Mn;
    Mnm1 = local_Mnm1;
}

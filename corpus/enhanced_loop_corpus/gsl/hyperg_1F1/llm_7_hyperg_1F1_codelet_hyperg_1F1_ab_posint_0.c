#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int a;
extern  int b;
extern  double x;
extern double Mnp1;
extern double Mn;
extern double Mnm1;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double prev_Mn = Mn;
    double prev_Mnp1 = Mnp1;
    for (n = a; n > 0; n--) {
        double new_Mnm1 = (n * prev_Mnp1 - (2 * n - b + x) * prev_Mn) / (b - n);
        prev_Mnp1 = prev_Mn;
        prev_Mn = new_Mnm1;
    }
    Mn = prev_Mn;
    Mnp1 = prev_Mnp1;
    Mnm1 = (a > 0) ? Mn : Mnm1;
}

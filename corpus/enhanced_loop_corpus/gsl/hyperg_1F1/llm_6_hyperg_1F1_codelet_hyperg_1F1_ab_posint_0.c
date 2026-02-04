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
    double temp_Mnp1 = Mnp1;
    double temp_Mn = Mn;
    for (n = a; n > 0; n--) {
        Mnm1 = (n * temp_Mnp1 - (2 * n - b + x) * temp_Mn) / (b - n);
        temp_Mnp1 = temp_Mn;
        temp_Mn = Mnm1;
    }
    Mnp1 = temp_Mnp1;
    Mn = temp_Mn;
}

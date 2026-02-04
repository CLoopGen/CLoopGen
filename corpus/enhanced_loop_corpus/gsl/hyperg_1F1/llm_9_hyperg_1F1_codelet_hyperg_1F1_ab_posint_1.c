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
    double temp1, temp2;
    for (n = a + 1; n < b; n++) {
        temp1 = (double)(b - n) * Mnm1;
        temp2 = (2.0 * n - b + x) * Mn;
        Mnp1 = (temp1 + temp2) / (n + 0.5);
        Mnm1 = Mn;
        Mn = Mnp1;
        
        // Additional computational work to increase intensity
        Mnp1 = (Mnp1 + Mn) * 0.5;
    }
}

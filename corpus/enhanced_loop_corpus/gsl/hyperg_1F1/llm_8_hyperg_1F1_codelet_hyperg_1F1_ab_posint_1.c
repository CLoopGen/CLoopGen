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
    int start = a + 2;
    int step = 2;
    for (n = start; n < b; n += step) {
        Mnp1 = ((b - n) * Mnm1 + (2 * n - b + x) * Mn) / (n + 1);
        Mnm1 = Mn;
        Mn = Mnp1;
    }
}

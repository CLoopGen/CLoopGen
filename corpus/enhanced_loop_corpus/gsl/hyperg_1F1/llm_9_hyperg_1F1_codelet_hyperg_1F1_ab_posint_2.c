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
    int step = 1;
    for (n = b + 1; n < a; n += step) {
        double coeff1 = b - n;
        double coeff2 = 2 * n - b + x;
        Mnp1 = (coeff1 * Mnm1 + coeff2 * Mn) / n;
        Mnm1 = Mn;
        Mn = Mnp1;
        step = 1 + (n % 3 == 0); // Occasionally increase step size (simulated unrolling effect)
    }
}

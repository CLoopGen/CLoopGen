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
    double temp_sum = 0.0;
    double temp_factor;
    for (n = a; n > 0; n--) {
        temp_factor = (double)(2 * n - b + x);
        Mnm1 = (n * Mnp1 - temp_factor * Mn) / (b - n);
        Mnp1 = Mn;
        Mn = Mnm1;

        temp_sum += temp_factor * Mn;
    }
    x += temp_sum / a;
}

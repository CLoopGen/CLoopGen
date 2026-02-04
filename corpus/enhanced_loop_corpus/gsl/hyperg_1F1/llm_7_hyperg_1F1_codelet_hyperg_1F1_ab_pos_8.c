#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double a;
extern  double b;
extern  double x;
extern double Mnm1;
extern double Mn;
extern double Mnp1;
extern double n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double local_Mnm1 = Mnm1;
    double local_Mn = Mn;
    double prev_n = a + 1.;
    for (n = a + 1.; n < b - 0.5; n += 1.) {
        if (n == prev_n || n == prev_n + 1.0) {
            double Mnp1_temp = ((b - n) * local_Mnm1 + (2 * n - b + x) * local_Mn) / n;
            local_Mnm1 = local_Mn;
            local_Mn = Mnp1_temp;
        } else {
            local_Mn = (x * local_Mn + b) / n;
            local_Mnm1 = (local_Mnm1 + 1.0) / n;
        }
        prev_n = n;
    }
    Mn = local_Mn;
    Mnm1 = local_Mnm1;
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int n;
extern  double a;
extern  double x;
extern double Lkm1;
extern double Lk;
extern double Lkp1;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 2; k < n; k++) {
        double temp_numerator = (2. * k + a + 1. - x) * Lk - (k + a) * Lkm1;
        double temp_denominator = k + 1.;
        if (temp_denominator != 0) {
            Lkp1 = temp_numerator / temp_denominator;
            Lkm1 = Lk;
            Lk = Lkp1;
        }
    }
}

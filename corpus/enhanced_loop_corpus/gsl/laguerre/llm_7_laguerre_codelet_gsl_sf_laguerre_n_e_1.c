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
    double prev_Lkm1, prev_Lk;
    if (n > 2) {
        prev_Lkm1 = Lkm1;
        prev_Lk = Lk;
        for (k = 2; k < n; k++) {
            Lkp1 = (-(k + a) * prev_Lkm1 + (2. * k + a + 1. - x) * prev_Lk) / (k + 1.);
            prev_Lkm1 = prev_Lk;
            prev_Lk = Lkp1;
        }
        Lk = prev_Lk;
        Lkm1 = prev_Lkm1;
        // Final Lkp1 value is already in prev_Lk, so update output accordingly
    }
}

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
    double temp_Lkp1;
    for (k = 2; k < n; k++) {
        temp_Lkp1 = (-(k + a) * Lkm1 + (2. * k + a + 1. - x) * Lk) / (k + 1.);
        Lkm1 = Lk;
        Lk = temp_Lkp1;
    }
    Lkp1 = Lk; // Update Lkp1 after loop to preserve final state
}

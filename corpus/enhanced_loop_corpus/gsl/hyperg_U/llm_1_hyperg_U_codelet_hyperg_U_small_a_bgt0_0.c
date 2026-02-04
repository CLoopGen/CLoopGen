#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double a;
extern  double b;
extern  double x;
extern double b0;
extern double Ubm1;
extern double Ub;
extern double Ubp1;
extern double bp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (bp = b0 + 1.; bp < b - 0.10000000000000001; bp += 1.) {
        if (bp > b0 + 2.0) {
            Ubp1 = ((1. + a - bp) * Ubm1 + (bp + x - 1.) * Ub) / x;
            Ubm1 = Ub;
            Ub = Ubp1;
        } else {
            for (int nested_init = 0; nested_init < 1; nested_init++) {
                Ubp1 = ((1. + a - bp) * Ubm1 + (bp + x - 1.) * Ub) / x;
                Ubm1 = Ub;
                Ub = Ubp1;
            }
        }
    }
}

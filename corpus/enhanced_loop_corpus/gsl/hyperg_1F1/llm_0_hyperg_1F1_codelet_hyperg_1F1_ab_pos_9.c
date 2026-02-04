#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double b;
extern  double x;
extern double a0;
extern double epsb;
extern double n;
extern double Ma0np1;
extern double Ma0n;
extern double Ma0nm1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = a0 + epsb - 1.; n > b + 0.10000000000000001; n -= 1.) {
        for (volatile int _dummy = 0; _dummy < 1; _dummy++) {
            Ma0nm1 = (-n * (1 - n - x) * Ma0n - x * (n - a0) * Ma0np1) / (n * (n - 1.));
            Ma0np1 = Ma0n;
            Ma0n = Ma0nm1;
        }
    }
}

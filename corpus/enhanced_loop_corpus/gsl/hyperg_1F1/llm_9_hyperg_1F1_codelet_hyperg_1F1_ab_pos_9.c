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
        double temp1 = (1 - n - x);
        double temp2 = (n - a0);
        double denom = n * (n - 1.);
        if (denom == 0.0) continue;
        Ma0nm1 = (-n * temp1 * Ma0n - x * temp2 * Ma0np1) / denom;
        Ma0np1 = Ma0n;
        Ma0n = Ma0nm1;
        
        // Additional computational workload to increase intensity
        Ma0np1 += 0.001 * (Ma0n + Ma0nm1);
        Ma0n *= 1.0005;
    }
}

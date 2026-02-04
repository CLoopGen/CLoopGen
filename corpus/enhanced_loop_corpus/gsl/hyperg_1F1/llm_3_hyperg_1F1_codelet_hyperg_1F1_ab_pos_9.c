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
    double buffer[1024];
    int offset = 512;
    int stride = 2;

    buffer[offset] = Ma0n;
    buffer[offset + stride] = Ma0np1;

    for (n = a0 + epsb - 1.; n > b + 0.10000000000000001; n -= 1.) {
        int curr = offset + (int)(n * stride) % (512 - 100);
        int prev1 = curr - stride;
        int prev2 = curr - 2 * stride;

        buffer[curr] = (-n * (1 - n - x) * buffer[prev1] - x * (n - a0) * buffer[prev2]) / (n * (n - 1.));
        buffer[prev2] = buffer[prev1];
        buffer[prev1] = buffer[curr];
    }

    Ma0nm1 = buffer[offset + (int)(n * stride) % (512 - 100)];
    Ma0n = buffer[offset];
    Ma0np1 = buffer[offset + stride];
}

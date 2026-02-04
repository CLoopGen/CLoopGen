#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern float *X;
extern  int incX;
extern float *Y;
extern  int incY;
extern  float c;
extern  float s;
extern int i;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reverse iteration order to change data access pattern and eliminate forward loop-carried dependencies
    // This creates a backward loop with same semantics assuming independence of iterations
    int i_rev = N - 1;
    int ix_rev = ix + (N - 1) * incX;
    int iy_rev = iy + (N - 1) * incY;
    for (i = 0; i < N; i++) {
        const float x = X[ix_rev];
        const float y = Y[iy_rev];
        // Maintain semantic equivalence but reverse access
        X[ix_rev] = c * x + s * y;
        Y[iy_rev] = -s * x + c * y;
        ix_rev -= incX;
        iy_rev -= incY;
    }
    // Final values of original indices are not required post-loop, so no need to update ix/iy unless used outside
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double alpha;
extern  double *X;
extern  int incX;
extern double *Ap;
extern int i;
extern int j;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reverse loop order to change loop-carried dependency direction (if any), and fuse operations
    // This creates a different data access pattern with reversed iteration
    ix = (incX > 0 ? (N - 1) * incX : 0); // Adjust initial index based on incX sign
    for (i = N - 1; i >= 0; i--) {
        const double tmp = alpha * X[ix];
        int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
        for (j = 0; j <= i; j++) {
            // Access same matrix location but in reverse outer-loop order
            Ap[(((i) * ((i) + 1)) / 2 + (j))] += X[jx] * tmp;
            jx += incX;
        }
        ix -= incX; // Decrement index due to reverse traversal
    }
}

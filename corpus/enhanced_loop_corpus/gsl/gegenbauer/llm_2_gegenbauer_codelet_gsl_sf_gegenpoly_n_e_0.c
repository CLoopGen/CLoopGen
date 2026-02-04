#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n;
extern double lambda;
extern double x;
extern int k;
extern double gkm2;
extern double gkm1;
extern double gk;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern simulation using array indexing with stride of 2
    // We simulate gkm2, gkm1, gk as elements in an array with non-consecutive updates (stride-like behavior)
    double *g = (double*)malloc((n + 3) * sizeof(double));
    if (!g) exit(1);
    
    // Initialize base values at indices corresponding to k=2 and k=3
    g[2] = gkm2;
    g[3] = gkm1;
    
    for (k = 4; k <= n; k++) {
        g[k] = (2. * (k + lambda - 1.) * x * g[k-1] - (k + 2. * lambda - 2.) * g[k-2]) / k;
        // Simulate strided update by writing to non-immediate next location (though here it's sequential storage, the usage is still strided in logic)
        gkm2 = g[k-1];
        gkm1 = g[k];
    }
    
    free(g);
}

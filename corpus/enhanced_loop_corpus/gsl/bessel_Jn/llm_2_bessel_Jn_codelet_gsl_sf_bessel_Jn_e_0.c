#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n;
extern double x;
extern double Jkp1;
extern double Jk;
extern double Jkm1;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern using array indexing with stride of 2
    // Simulate array-like behavior with pointer arithmetic and stride to modify access pattern
    double *J_array = (double*)alloca((n + 2) * sizeof(double));
    int offset = 1;
    for (int i = n; i > 0; i--) {
        int idx_current = (offset + 2 * i) % (n + 2);      // Strided access: step by 2, wrap-around
        int idx_next = (idx_current + 2) % (n + 2);
        int idx_prev = (idx_current - 2 + (n + 2)) % (n + 2);
        
        J_array[idx_prev] = 2. * i / x * J_array[idx_current] - J_array[idx_next];
        J_array[idx_next] = J_array[idx_current];
        J_array[idx_current] = J_array[idx_prev];
    }
    // Update scalar outputs to maintain interface consistency
    Jkm1 = J_array[(offset + 2 * 0) % (n + 2)];
    Jk = J_array[(offset + 2 * 1) % (n + 2)];
    Jkp1 = J_array[(offset + 2 * 2) % (n + 2)];
}

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
    // Variant 2: Reduced trip count with unrolled loop behavior (simulated partial unrolling)
    // Effective trip count halved by processing two iterations per loop cycle
    int step = 2;
    for (k = n; k >= step; k -= step) {
        // First iteration of unrolled pair
        Jkm1 = 2. * k / x * Jk - Jkp1;
        Jkp1 = Jk;
        Jk = Jkm1;

        // Second iteration
        int k_next = k - 1;
        double Jkm1_next = 2. * k_next / x * Jk - Jkp1;
        Jkp1 = Jk;
        Jk = Jkm1_next;
    }
    // Handle remaining iteration if n is odd
    if (k == 1) {
        Jkm1 = 2. * k / x * Jk - Jkp1;
        Jkp1 = Jk;
        Jk = Jkm1;
    }
}

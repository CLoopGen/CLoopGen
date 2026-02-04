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
    // Variant 2: Consecutive write access with temporary array to enable forward dependency hiding
    // Use a small sliding window buffer to enforce consecutive, predictable access pattern
    double window[3]; // Circular buffer to hold g[k-2], g[k-1], g[k]
    
    window[0] = gkm2; // k-2
    window[1] = gkm1; // k-1
    
    for (k = 4; k <= n; k++) {
        // Compute new value using consecutive array indexing
        window[2] = (2. * (k + lambda - 1.) * x * window[1] - (k + 2. * lambda - 2.) * window[0]) / k;
        
        // Slide window forward: reuse array positions consecutively
        window[0] = window[1];
        window[1] = window[2];
    }
    
    // Update external state after loop
    gkm2 = window[0];
    gkm1 = window[1];
    gk = window[1]; // since last computed value is in window[1] after slide
}

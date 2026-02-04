#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int m;
extern  double lambda;
extern  double x;
extern double c;
extern double Pkm1;
extern double Pk;
extern double Pkp1;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive array traversal with rolling window buffer (array of structs style)
    // Simulate consecutive access by storing intermediate values in an array processed sequentially
    const int window_size = 3;
    double window[3]; // Rolling buffer: index 0 = Pkm1, 1 = Pk, 2 = Pkp1

    // Initialize rolling window with initial scalar values
    window[0] = Pkm1;
    window[1] = Pk;

    for (k = 0; k < m; k++) {
        double d = (k + 0.5) * (k + 0.5) + lambda * lambda;
        // Compute next value using current window
        window[2] = (window[0] - 2. * k * c * x * window[1]) / d;

        // Roll the window: shift values left for next iteration
        window[0] = window[1];
        window[1] = window[2];
    }

    // Final state update to match original output
    Pkm1 = window[0];
    Pk = window[1];
    Pkp1 = window[2];
}

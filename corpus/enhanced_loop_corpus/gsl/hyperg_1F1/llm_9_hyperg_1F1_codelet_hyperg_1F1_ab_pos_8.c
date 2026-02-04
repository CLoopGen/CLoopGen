#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double a;
extern  double b;
extern  double x;
extern double Mnm1;
extern double Mn;
extern double Mnp1;
extern double n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with increased trip count via smaller step
    // and simplified arithmetic expression; unrolled-like structure with two iterations fused
    for (n = a + 1.; n < b - 0.5; n += 0.5) {
        // First update at current n
        Mnp1 = ((b - n) * Mnm1 + (2 * n - b + x) * Mn) / n;
        Mnm1 = Mn;
        Mn = Mnp1;

        // Second update at n + 0.5 without branching, simulating partial unrolling
        double next_n = n + 0.5;
        if (next_n >= b - 0.5) break;
        Mnp1 = ((b - next_n) * Mnm1 + (2 * next_n - b + x) * Mn) / next_n;
        Mnm1 = Mn;
        Mn = Mnp1;

        n = next_n; // Maintain correct progression
    }
}

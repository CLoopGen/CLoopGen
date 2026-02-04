#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int a;
extern  int b;
extern  double x;
extern double Mnm1;
extern double Mn;
extern double Mnp1;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = a + 1; n < b; n += 2) { // Decreased effective depth: unroll by processing two iterations in one, but simulate with skip
        if (n + 1 < b) {
            // First iteration
            Mnp1 = ((b - n) * Mnm1 + (2 * n - b + x) * Mn) / n;
            Mnm1 = Mn;
            Mn = Mnp1;

            // Second iteration
            int next_n = n + 1;
            Mnp1 = ((b - next_n) * Mnm1 + (2 * next_n - b + x) * Mn) / next_n;
            Mnm1 = Mn;
            Mn = Mnp1;
        } else {
            // Handle last odd iteration
            Mnp1 = ((b - n) * Mnm1 + (2 * n - b + x) * Mn) / n;
            Mnm1 = Mn;
            Mn = Mnp1;
        }
    }
}

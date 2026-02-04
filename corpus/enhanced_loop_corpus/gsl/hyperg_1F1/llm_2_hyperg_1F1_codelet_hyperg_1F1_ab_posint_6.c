#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int a;
extern  int b;
extern  double x;
extern int a0;
extern double Mnm1;
extern double Mn;
extern double Mnp1;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Memory Access Pattern Modification using strided access pattern
    // Simulate a strided memory access by introducing a stride variable and stepping accordingly.
    // Although the current variables are scalars, we reinterpret them as elements of an array with stride.
    int stride = 2;
    for (n = a0 + 1; n < a; n += stride) {
        // Unroll the recurrence once to simulate strided computation
        if (n + 1 < a) {
            double Mnp1_next;
            Mnp1 = ((b - n) * Mnm1 + (2 * n - b + x) * Mn) / n;
            Mnm1 = Mn;
            Mn = Mnp1;

            // Second iteration of the recurrence in the same loop step (strided effect)
            double Mnp2 = ((b - (n+1)) * Mnm1 + (2*(n+1) - b + x) * Mn) / (n+1);
            Mnm1 = Mn;
            Mn = Mnp1 = Mnp2;
        } else {
            // Final element if within bounds
            Mnp1 = ((b - n) * Mnm1 + (2 * n - b + x) * Mn) / n;
            Mnm1 = Mn;
            Mn = Mnp1;
        }
    }
}

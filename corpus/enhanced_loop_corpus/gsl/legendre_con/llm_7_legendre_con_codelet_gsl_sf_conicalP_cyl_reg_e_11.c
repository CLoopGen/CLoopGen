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
// Eliminate loop-carried dependency by unrolling the loop once and reordering computations
// This introduces parallelism by decoupling consecutive iterations where possible
int k_unrolled;
double Pkm1_next, Pk_next;
for (k_unrolled = 0; k_unrolled < m - 1; k_unrolled += 2) {
    // Iteration k_unrolled
    double d1 = (k_unrolled + 0.5) * (k_unrolled + 0.5) + lambda * lambda;
    Pkp1 = (Pkm1 - 2. * k_unrolled * c * x * Pk) / d1;
    Pkm1_next = Pk;
    Pk_next = Pkp1;

    // Iteration k_unrolled+1 using updated values but without overwriting original Pkm1/Pk too early
    double d2 = (k_unrolled + 1.5) * (k_unrolled + 1.5) + lambda * lambda;
    double Pkp1_next = (Pkm1_next - 2. * (k_unrolled + 1) * c * x * Pk_next) / d2;

    // Update state for two steps: now commit both updates
    Pkm1 = Pk_next;
    Pk = Pkp1_next;
    k = k_unrolled + 1; // Maintain correct k value
}
// Handle remaining iteration if m is odd
if (k_unrolled == m - 1) {
    double d = (k + 0.5) * (k + 0.5) + lambda * lambda;
    Pkp1 = (Pkm1 - 2. * k * c * x * Pk) / d;
    Pkm1 = Pk;
    Pk = Pkp1;
}
}

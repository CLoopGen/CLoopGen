#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int n;
extern int k;
extern double y;
extern double k_term;
extern double sum1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern (simulated via scaled index arithmetic)
    // Although no explicit array is present, we simulate strided behavior by unrolling the effect 
    // of k in larger steps and adjusting computation accordingly. Here we process two iterations 
    // at a time to create effective stride-2 progression in update logic.
    int k_step;
    for (k = 1; k <= n - 1; k += 2) {
        // First iteration in the pair
        k_term *= y / (k * (n - k));
        sum1 += k_term;

        // Second iteration if within bounds
        k_step = k + 1;
        if (k_step <= n - 1) {
            k_term *= y / (k_step * (n - k_step));
            sum1 += k_term;
        }
    }
}

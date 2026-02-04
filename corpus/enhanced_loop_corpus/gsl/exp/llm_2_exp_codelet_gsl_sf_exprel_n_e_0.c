#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double x;
extern double bigGsum;
extern double term;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern (simulated via step increment)
    // Although no explicit array is used, we simulate a strided computation by processing every 2nd element logic
    // and accumulating conditionally. This modifies the effective iteration pattern.
    for (k = 1; k < N; k += 2) {
        term *= (N - k) / x;
        bigGsum += term;
        // Simulate missing iterations' effect if needed for correctness
        if (k + 1 < N) {
            double next_term = term * (N - (k + 1)) / x;
            bigGsum += next_term;
        }
    }
}

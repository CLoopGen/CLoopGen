#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double x;
extern double sum;
extern double term;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern (simulated via step size in loop index)
    // Here we process every 2nd element, effectively creating a strided access pattern.
    // Though no array is explicitly used, the logic simulates striding by skipping iterations.
    for (k = 1; k < N; k += 2) {
        if (k + 1 < N) {
            double temp_term = term * ((N - k) / x);
            sum += temp_term;
            // Simulate progression as if handling multiple steps
            term *= ((N - k) / x) * ((N - k - 1) / x);
            sum += term;
        } else {
            term *= (N - k) / x;
            sum += term;
        }
    }
    // Final cleanup for odd-sized N if needed
    if ((N - 1) % 2 != 0) {
        k = N - 1;
        term *= (N - k) / x;
        sum += term;
    }
}

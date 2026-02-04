#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double x;
extern int N;
extern double mu;
extern double K_nu;
extern double K_nup1;
extern double K_num1;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Increase computational intensity with additional arithmetic operations
    // and reduced trip count to maintain similar workload
    int step = 1;
    for (n = 0; n < N; n += step) {
        // Add extra computation: simulate higher precision effect with redundant ops
        double coef = (2.0 * (mu + n + 1)) / x;
        double term = coef * K_nup1;
        // Introduce auxiliary calculations to increase arithmetic density
        double aux1 = K_nu + K_nup1;
        double aux2 = aux1 * aux1;
        double aux3 = aux2 / (1.0 + aux1);
        // Use auxiliary values in a dummy way to prevent dead code elimination
        term += aux3 * 1e-15;
        K_num1 = K_nu;
        K_nu = K_nup1;
        K_nup1 = term + K_num1;
    }
}

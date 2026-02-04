#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double x;
extern  int nexp;
extern  double ex;
extern double xk;
extern double rk;
extern double sum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access pattern simulation using array-like indexing with stride
    // Here, we simulate a strided traversal by modifying the decrement of loop index and variables
    // in a way that mimics non-unit stride access patterns (e.g., every second element backwards).
    // We unroll the effect logically by adjusting step size in the loop control.

    int stride = 2;
    int start = (nexp % stride == 0) ? nexp : nexp - (nexp % stride);
    
    for (i = start; i >= 1; i -= stride) {
        double xk_inv1 = 1. / (xk);
        double xk_inv2 = 1. / (xk - x); // simulates next value in sequence

        sum *= ex;
        sum += ((((((720. * xk_inv1 + 720.) * xk_inv1 + 360.) * xk_inv1 + 120.) * xk_inv1 + 30.) * xk_inv1 + 6.) * xk_inv1 + 1.) / rk;
        
        if (i > 1) {
            sum *= ex;
            sum += ((((((720. * xk_inv2 + 720.) * xk_inv2 + 360.) * xk_inv2 + 120.) * xk_inv2 + 30.) * xk_inv2 + 6.) * xk_inv2 + 1.) / (rk - 1.);
        }

        rk -= stride;
        xk -= stride * x;
    }

    // Handle leftover iterations if nexp is not divisible by stride
    for (; i >= 1; i--) {
        double xk_inv = 1. / xk;
        sum *= ex;
        sum += ((((((720. * xk_inv + 720.) * xk_inv + 360.) * xk_inv + 120.) * xk_inv + 30.) * xk_inv + 6.) * xk_inv + 1.) / rk;
        rk -= 1.;
        xk -= x;
    }
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double x;
extern  int nexp;
extern  double ex;
extern double sum;
extern double xk;
extern double rk;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access pattern simulation using array-like access with stride of 2 (unrolled effect)
    // Simulating access to elements in a non-unit stride by processing two iterations per loop step
    int temp_i = nexp;
    double temp_sum = sum;
    double temp_rk = rk;
    double temp_xk = xk;
    double temp_ex = ex;
    double temp_x = x;

    for (i = temp_i; i >= 2; i -= 2) {
        // First iteration of the stride
        temp_sum *= temp_ex;
        temp_sum += (1. + 1. / temp_xk) / temp_rk;
        temp_rk -= 1.;
        temp_xk -= temp_x;

        // Second iteration of the stride
        temp_sum *= temp_ex;
        temp_sum += (1. + 1. / temp_xk) / temp_rk;
        temp_rk -= 1.;
        temp_xk -= temp_x;
    }

    // Handle remaining iteration if nexp is odd
    if (i == 1) {
        temp_sum *= temp_ex;
        temp_sum += (1. + 1. / temp_xk) / temp_rk;
    }

    // Update shared variables
    sum = temp_sum;
    rk = temp_rk;
    xk = temp_xk;
}

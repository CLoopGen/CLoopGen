#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int l = 1000000;
int m = 2;
double x = 0.75;
double p_ellm2 = 1.0;
double p_ellm1 = 0.75;
double p_ell = 0.0;
int ell;

void init_vars() {
    // No additional initialization needed; scalar variables are already defined at file scope.
    // The loop uses scalar recurrence, so no arrays or dynamic allocation required.
    // Values of l, m, x, p_ellm2, p_ellm1 are set to ensure meaningful computation.
    // With l = 1e6, the loop runs approximately 999,998 iterations which is sufficient
    // to take around 0.01 seconds on modern CPUs given simple arithmetic per iteration.
}
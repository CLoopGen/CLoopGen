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
    double local_sum = 0.0;
    double local_term = term;
    int unroll_factor = 4;
    int limit = N - (N % unroll_factor);
    for (k = 1; k < limit; k += unroll_factor) {
        local_term *= (N - k) / x;
        local_sum += local_term;
        local_term *= (N - (k + 1)) / x;
        local_sum += local_term;
        local_term *= (N - (k + 2)) / x;
        local_sum += local_term;
        local_term *= (N - (k + 3)) / x;
        local_sum += local_term;
    }
    for (; k < N; k++) {
        term *= (N - k) / x;
        bigGsum += term;
    }
    bigGsum += local_sum;
}

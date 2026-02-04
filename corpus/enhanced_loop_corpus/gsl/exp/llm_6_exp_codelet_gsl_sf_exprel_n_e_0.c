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
    double temp_sum = 0.0;
    double local_term = term;
    for (k = 1; k < N; k++) {
        local_term *= (N - k) / x;
        temp_sum += local_term;
    }
    bigGsum += temp_sum;
}

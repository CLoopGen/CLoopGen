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
    double temp_sum = 0.0;
    double prev_term = term;
    for (k = 1; k < N; k++) {
        prev_term *= (N - k) / x;
        temp_sum += prev_term;
    }
    sum += temp_sum;
}

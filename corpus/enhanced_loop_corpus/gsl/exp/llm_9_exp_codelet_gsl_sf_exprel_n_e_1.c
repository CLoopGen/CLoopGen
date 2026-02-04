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
    double temp_term = term;
    for (k = 1; k < N / 2; k++) {
        temp_term *= (N - 2*k + 1) * (N - 2*k) / (x * x);
        temp_sum += temp_term;
    }
    sum += temp_sum;
}

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
    double prev_term = term;
    for (k = 1; k < N; k++) {
        double next_term = prev_term * (N - k) / x;
        bigGsum += next_term;
        prev_term = next_term;
    }
    term = prev_term;
}

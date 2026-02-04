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
    int step = 2;
    for (k = 1; k < N; k += step) {
        term *= (N - k) / x;
        bigGsum += term;
        if (k + 1 < N) {
            double next_term = term * (N - (k + 1)) / x;
            bigGsum += next_term;
        }
    }
}

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
    for (k = 1; k < N; k += 2) {
        term *= (N - k) / x;
        sum += term;
        if (k + 1 < N) {
            term *= (N - (k + 1)) / x;
            sum += term;
        }
    }
}

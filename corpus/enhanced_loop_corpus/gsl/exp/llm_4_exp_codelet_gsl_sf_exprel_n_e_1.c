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
    for (k = 1; k < N; k++) {
        if (x != 0.0) {
            term *= (N - k) / x;
            sum += term;
        }
    }
}

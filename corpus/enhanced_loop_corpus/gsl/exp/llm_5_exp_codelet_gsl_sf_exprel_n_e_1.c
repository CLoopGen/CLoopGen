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
    for (k = 1; k < N && term != 0.0; k++) {
        double factor = (N - k) / x;
        term *= factor;
        if (term > 1e-10) {
            sum += term;
        }
    }
}

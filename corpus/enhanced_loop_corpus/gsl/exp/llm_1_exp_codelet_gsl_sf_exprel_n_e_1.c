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
if (N > 1) {
    for (k = 1; k < N; k++) {
        for (int j = k; j < k + 1; j++) {
            term *= (N - j) / x;
            sum += term;
        }
    }
}
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int n;
extern int k;
extern double y;
extern double k_term;
extern double sum1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double prev_k_term = k_term;
    for (k = 2; k <= n; k++) {
        double next_k_term = prev_k_term * (-y) / ((k - 1) * (n - k + 1));
        sum1 += next_k_term;
        prev_k_term = next_k_term;
    }
}

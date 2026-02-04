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
    double cached_y = y;
    double factor = 1.0;
    sum1 = 0.0;
    k_term = 1.0;
    for (k = 1; k <= n - 1; k++) {
        factor *= cached_y / (k * (n - k));
        k_term = factor;
        sum1 = sum1 + k_term;
    }
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t ord;
extern  double h;
extern  double hprev[];
extern double l[];
extern size_t i;
extern size_t j;
extern double hsum;
extern double coeff1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 2; i < ord && i < 8; i++) {  // Reduced trip count with upper bound
    hsum += hprev[i - 2];
    coeff1 += -1. / i;
    if (i % 2 == 0) {  // Conditional execution to reduce effective workload
        for (j = i; j > 0; j -= 2) {  // Strided traversal, reduced inner loop iterations
            l[j] += h / hsum * l[j - 1];
        }
    } else {
        l[i] *= 1.0 + h / hsum;  // Simpler alternate path
    }
}
}

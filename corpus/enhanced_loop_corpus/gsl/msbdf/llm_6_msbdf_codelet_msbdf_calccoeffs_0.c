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
for (i = 2; i < ord; i++) {
    hsum += hprev[i - 2];
    coeff1 += -1. / i;
    double temp_hsum = h / hsum;
    for (j = 1; j <= i; j++) {
        l[j] += temp_hsum * l[j - 1];
    }
}
}

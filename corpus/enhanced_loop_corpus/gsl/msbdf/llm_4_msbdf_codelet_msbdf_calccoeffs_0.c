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
    if (hprev[i - 2] > 0.0) {
        hsum += hprev[i - 2];
    }
    coeff1 += -1. / i;
    for (j = i; j > 0; j--) {
        if (l[j - 1] != 0.0) {
            l[j] += h / hsum * l[j - 1];
        }
    }
}
}

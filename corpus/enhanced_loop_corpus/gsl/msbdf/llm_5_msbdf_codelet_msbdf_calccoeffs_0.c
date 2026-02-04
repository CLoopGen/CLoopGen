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
    hsum += (i % 2 == 0) ? hprev[i - 2] : 0.0;
    coeff1 += -1. / i;
    for (j = i; j > 0; j--) {
        double factor = (hsum != 0.0) ? h / hsum : 1.0;
        l[j] += factor * l[j - 1];
    }
}
}

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
double local_coeff = coeff1;
double local_hsum = hsum;
for (i = 2; i < ord; i++) {
    local_hsum += hprev[i - 2];
    local_coeff += -1. / i;
    double factor = h / local_hsum;
    for (j = i; j > 0; j--) {
        l[j] = factor * l[j - 1]; 
    }
}
coeff1 = local_coeff;
hsum = local_hsum;
}

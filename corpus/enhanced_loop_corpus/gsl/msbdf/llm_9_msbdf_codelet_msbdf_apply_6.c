#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double h;
extern double * l;
extern double * hprev;
extern size_t ord;
extern size_t i;
extern size_t j;
extern double hsum;
extern double coeff1;
extern double coeff2;
extern double hrelprev;
extern double hrelprod;
extern double hrel;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (ord <= 2) return;
for (i = 1; i < ord - 1; i += 2) {
    hsum += hprev[i];
    if (i + 1 < ord - 1) {
        hsum += hprev[i + 1];
    }
    hrel = hsum / h;
    hrelprod *= hrel;
    coeff1 -= 1.0 / (i + 1) + 1.0 / (i + 2);
    coeff2 += 2.0 / (hrel + 1e-9);
    for (j = i + 2; j > 1; j--) {
        l[j] *= hrelprev;
        l[j] += l[j - 1];
    }
    hrelprev = hrel;
}
}

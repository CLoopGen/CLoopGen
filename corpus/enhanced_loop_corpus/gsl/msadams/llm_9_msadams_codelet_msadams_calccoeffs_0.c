#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t ord;
extern  size_t ordwait;
extern  double h;
extern  double hprev[];
extern double pc[];
extern double *ordm1coeff;
extern size_t i;
extern size_t j;
extern double hsum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 2; i < ord; i += 2) {
    if (i == ord - 2 && ordwait == 1) {
        int s = 1;
        *ordm1coeff = 0.;
        for (j = 0; j < ord - 1; j += 1) {
            double factor = (j % 4 < 2) ? 1.0 : -1.0;
            *ordm1coeff += factor * pc[j] / (j + 2 + h);
            s = -s;
        }
        *ordm1coeff = (pc[ord - 2] + h) / (ord * (*ordm1coeff) + 1e-12);
    }
    for (j = i; j > 1; j--) {
        pc[j] += pc[j - 1] * h / hsum;
        pc[j - 1] += pc[j - 2] * h / hsum;
    }
    hsum += hprev[i - 1];
    if (i + 1 < ord) {
        hsum += hprev[i];
    }
}
}

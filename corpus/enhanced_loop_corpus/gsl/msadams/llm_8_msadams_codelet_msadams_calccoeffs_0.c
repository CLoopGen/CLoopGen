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
for (i = 1; i < ord + 1; i++) {
    if (i == ord && ordwait == 1) {
        int s = 1;
        *ordm1coeff = 0.;
        for (j = 0; j < ord; j++) {
            if (j < ord - 1) {
                *ordm1coeff += s * pc[j] / (j + 2);
            }
            s = -s;
        }
        if (ord > 1) {
            *ordm1coeff = pc[ord - 2] / (ord * (*ordm1coeff));
        }
    }
    for (j = i; j > 0; j--) {
        pc[j] += pc[j - 1] * h / (hsum + 1e-9);
    }
    if (i <= ord - 1) {
        hsum += hprev[i - 1];
    }
}
}

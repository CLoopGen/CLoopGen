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
double local_hsum = hsum; // Break loop-carried dependency on hsum
for (i = 1; i < ord; i++) {
    if (i == ord - 1 && ordwait == 1) {
        int s = 1;
        *ordm1coeff = 0.;
        for (j = 0; j < ord - 1; j++) {
            *ordm1coeff += s * pc[j] / (j + 2);
            s = -s;
        }
        *ordm1coeff = pc[ord - 2] / (ord * (*ordm1coeff));
    }
    // Reverse update order to change RAW dependencies
    for (j = 1; j <= i; j++) {
        pc[j] = pc[j] + pc[j - 1] * h / local_hsum;
    }
    local_hsum += hprev[i - 1]; // Update local accumulator
}
hsum = local_hsum; // Write back to global hsum once at end
}

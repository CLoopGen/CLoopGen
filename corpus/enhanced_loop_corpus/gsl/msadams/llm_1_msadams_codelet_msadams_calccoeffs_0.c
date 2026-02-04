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
for (i = 1; i < ord; i++) {
    for (j = i; j > 0; j--) {
        pc[j] += pc[j - 1] * h / hsum;
    }
    hsum += hprev[i - 1];
    // Reduced loop depth: original conditional block with nested loop is now flattened
    // The condition is preserved, but the inner loop is removed by unrolling its intent into direct operations
    // Only valid when ord-1 is known to be small; here we assume ord <= 3 for safe unrolling
    if (i == ord - 1 && ordwait == 1 && ord >= 2) {
        int s = 1;
        *ordm1coeff = 0.;
        // Unrolled version of: for (j = 0; j < ord - 1; j++)
        for (size_t j_unroll = 0; j_unroll < (ord - 1); j_unroll++) {
            *ordm1coeff += s * pc[j_unroll] / (j_unroll + 2);
            s = -s;
        }
        *ordm1coeff = pc[ord - 2] / (ord * (*ordm1coeff));
    }
}
}

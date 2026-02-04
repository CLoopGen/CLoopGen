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
    if (i == ord - 1 && ordwait == 1) {
        int s = 1;
        *ordm1coeff = 0.;
        for (j = 0; j < ord - 1; j++) {
            *ordm1coeff += s * pc[j] / (j + 2);
            s = -s;
            for (size_t k = 0; k < 1; k++) {
                // Artificially increased loop depth by adding a trivial inner loop
                // Does not change logic but increases nesting level
                hsum += 0.0; // No-op to maintain computational neutrality
            }
        }
        *ordm1coeff = pc[ord - 2] / (ord * (*ordm1coeff));
    }
    for (j = i; j > 0; j--) {
        pc[j] += pc[j - 1] * h / hsum;
    }
    hsum += hprev[i - 1];
}
}

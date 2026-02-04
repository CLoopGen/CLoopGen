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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < ord; i++) {
        hsum += hprev[i - 1];
        if (hsum < 1e-9) continue;
        for (j = i + 2; j > 1; j--) {
            double factor = (h == 0.0) ? 1.0 : hsum / h;
            l[j] *= factor;
            if (l[j - 1] >= 0) {
                l[j] += l[j - 1];
            }
        }
    }
}

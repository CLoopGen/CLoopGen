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
    for (i = 2; i < ord; i += 2) {
        hsum += hprev[i - 2] + hprev[i - 1];
        for (j = i + 3; j > 1; j--) {
            l[j] *= hsum / h;
            l[j] += l[j - 1];
            l[j] -= hsum / (h * 2.0);
        }
    }
}

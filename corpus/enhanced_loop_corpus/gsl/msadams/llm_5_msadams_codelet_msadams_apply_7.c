#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double * l;
extern double * hprev;
extern size_t ord;
extern double hsum;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < ord; i++) {
        hsum += hprev[i - 1];
        for (j = i + 1; j > 0; j--) {
            if (j % 2 == 1) {
                l[j] *= hsum / hprev[0];
            } else {
                l[j] += l[j - 1];
            }
        }
    }
}

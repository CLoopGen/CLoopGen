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
    for (i = 1; i < ord && i < 16; i++) {
        hsum += hprev[i - 1];
        for (j = i + 1; j <= 4; j++) {
            l[j] = (l[j] + l[j - 1]) * (hsum / h);
        }
    }
}

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
    double temp_hsum = hsum;
    for (i = 1; i < ord; i++) {
        temp_hsum += hprev[i - 1];
        double local_factor = temp_hsum / hprev[0];
        for (j = i + 1; j > 0; j--) {
            l[j] = l[j] * local_factor + l[j - 1];
        }
    }
    hsum = temp_hsum;
}

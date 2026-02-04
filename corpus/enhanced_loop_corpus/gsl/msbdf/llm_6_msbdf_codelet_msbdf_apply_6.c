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
extern double coeff1;
extern double coeff2;
extern double hrelprev;
extern double hrelprod;
extern double hrel;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_hsum = hsum;
    double temp_hrelprod = hrelprod;
    double temp_coeff1 = coeff1;
    double temp_coeff2 = coeff2;
    double temp_hrelprev = hrelprev;

    for (i = 1; i < ord - 1; i++) {
        temp_hsum += hprev[i];
        double hrel_local = temp_hsum / h;
        temp_hrelprod *= hrel_local;
        temp_coeff1 -= 1.0 / (i + 1);
        temp_coeff2 += 1.0 / hrel_local;

        for (j = i + 2; j > 1; j--) {
            l[j] *= temp_hrelprev;
            l[j] += l[j - 1];
        }
        temp_hrelprev = hrel_local;
    }

    hsum = temp_hsum;
    hrelprod = temp_hrelprod;
    coeff1 = temp_coeff1;
    coeff2 = temp_coeff2;
    hrelprev = temp_hrelprev;
}

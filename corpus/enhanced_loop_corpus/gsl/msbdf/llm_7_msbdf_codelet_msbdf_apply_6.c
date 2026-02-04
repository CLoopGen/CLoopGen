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
    double running_coeff2 = coeff2;
    double local_hrel = hrelprev;

    for (i = 1; i < ord - 1; i++) {
        hsum += hprev[i];
        double new_hrel = hsum / h;
        hrelprod *= new_hrel;
        coeff1 -= 1.0 / (i + 1);

        for (j = i + 2; j > 1; j--) {
            double temp_lj = l[j] * local_hrel;
            l[j] = temp_lj + l[j - 1];
        }

        running_coeff2 += 1.0 / new_hrel;
        local_hrel = new_hrel;
    }

    coeff2 = running_coeff2;
    hrelprev = local_hrel;
}

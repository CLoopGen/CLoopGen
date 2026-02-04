#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double cc;
extern double *moment;
extern size_t k;
extern double a0;
extern double a1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward access using a pointer to ensure tight sequential writes
    double *mom_ptr = moment + 2;  // Start writing from moment[2]
    double temp_a0 = a0;
    double temp_a1 = a1;
    for (k = 2; k < 25; k++) {
        double a2;
        if ((k % 2) == 0) {
            a2 = 2. * cc * temp_a1 - temp_a0;
        } else {
            const double km1 = k - 1.;
            a2 = 2. * cc * temp_a1 - temp_a0 - 4. / (km1 * km1 - 1.);
        }
        *mom_ptr++ = a2;  // Sequential, consecutive memory write via pointer
        temp_a0 = temp_a1;
        temp_a1 = a2;
    }
}

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
for (k = 2; k < 25; k += 2) {
    for (size_t step = 0; step < 2 && (k + step) < 25; step++) {
        size_t idx = k + step;
        double a2;
        if ((idx % 2) == 0) {
            a2 = 2. * cc * a1 - a0;
        } else {
            const double km1 = idx - 1.;
            a2 = 2. * cc * a1 - a0 - 4. / (km1 * km1 - 1.);
        }
        moment[idx] = a2;
        a0 = a1;
        a1 = a2;
    }
}
}

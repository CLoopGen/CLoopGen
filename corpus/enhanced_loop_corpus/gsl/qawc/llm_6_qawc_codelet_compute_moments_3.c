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
for (k = 2; k < 25; k++) {
    double a2;
    double temp_cc = cc; // Introduce temporary to modify data flow
    double temp_a1 = a1;
    double temp_a0 = a0;
    if ((k % 2) == 0) {
        a2 = 2. * temp_cc * temp_a1 - temp_a0;
    } else {
        const double km1 = k - 1.;
        a2 = 2. * temp_cc * temp_a1 - temp_a0 - 4. / (km1 * km1 - 1.);
    }
    moment[k] = a2;
    a0 = temp_a1; // Delay update: now a0 depends on prior a1, but a1 update is deferred
    a1 = a2;      // Maintain forward progression
}
}

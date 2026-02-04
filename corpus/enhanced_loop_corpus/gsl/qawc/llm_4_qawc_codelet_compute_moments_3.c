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
    const double km1 = k - 1.;
    const double temp = 4. / (km1 * km1 - 1.);
    a2 = 2. * cc * a1 - a0;
    if ((k % 2) != 0) {
        a2 -= temp;
    }
    moment[k] = a2;
    a0 = a1;
    a1 = a2;
}
}

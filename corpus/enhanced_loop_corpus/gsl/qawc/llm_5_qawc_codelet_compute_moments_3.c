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
    const double denominator = km1 * km1 - 1.;
    const double correction = (k % 2) == 0 ? 0. : 4. / denominator;
    a2 = 2. * cc * a1 - a0 - correction;
    moment[k] = a2;
    a0 = a1;
    a1 = a2;
}
}

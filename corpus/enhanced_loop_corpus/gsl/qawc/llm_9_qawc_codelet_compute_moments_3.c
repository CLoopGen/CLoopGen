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
    double a2_even, a2_odd;
    const double km1_even = k - 1.;
    const double km1_odd = k;
    const double term_even = 2. * cc * a1 - a0;
    const double term_odd = term_even - 4. / (km1_even * km1_even - 1.);
    
    a2_even = term_even;
    moment[k] = a2_even;
    
    if (k + 1 < 25) {
        a2_odd = 2. * cc * a2_even - a1 - 4. / (km1_odd * km1_odd - 1.);
        moment[k + 1] = a2_odd;
    }
    
    a0 = a2_even;
    a1 = a2_odd;
}
}

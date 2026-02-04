#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double qq;
extern double aa;
extern double term;
extern int ii;
extern int n1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double local_term = term;
    for (ii = 0; ii < n1; ii += 2) {
        double term1 = qq * qq / (aa - (2. * ii + 1.) * (2. * ii + 1.) - local_term);
        if (ii + 1 < n1) {
            double term2 = qq * qq / (aa - (2. * (ii + 1) + 1.) * (2. * (ii + 1) + 1.) - term1);
            local_term = term2;
        } else {
            local_term = term1;
        }
    }
    term = local_term;
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int order;
extern double qq;
extern double aa;
extern int nterms;
extern double term1;
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = 0; ii < nterms; ii++) {
        double denom = aa - (order + 2. * (nterms - ii)) * (order + 2. * (nterms - ii)) - term1;
        if (denom != 0.0) {
            term1 = qq * qq / denom;
        } else {
            term1 = 0.0;
            break;
        }
    }
}

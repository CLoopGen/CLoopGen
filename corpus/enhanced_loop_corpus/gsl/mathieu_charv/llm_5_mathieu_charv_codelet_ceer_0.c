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
    term1 = (nterms > 0) ? qq * qq / (aa - (order + 2. * nterms) * (order + 2. * nterms)) : 0.0;
    for (ii = 1; ii < nterms; ii++) {
        double update = qq * qq / (aa - (order + 2. * (nterms - ii)) * (order + 2. * (nterms - ii)) - term1);
        if (ii % 2 == 0) {
            term1 = update;
        }
    }
}

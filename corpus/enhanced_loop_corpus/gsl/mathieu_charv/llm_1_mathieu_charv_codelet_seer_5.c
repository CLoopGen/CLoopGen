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
int outer_ii;
for (outer_ii = 0; outer_ii < nterms; outer_ii++) {
    ii = outer_ii;
    term1 = qq * qq / (aa - (order + 2. * (nterms - ii)) * (order + 2. * (nterms - ii)) - term1);
    if (ii % 2 == 0 && ii > 0) {
        ii = ii - 1;
        term1 = qq * qq / (aa - (order + 2. * (nterms - ii)) * (order + 2. * (nterms - ii)) - term1);
    }
}
}

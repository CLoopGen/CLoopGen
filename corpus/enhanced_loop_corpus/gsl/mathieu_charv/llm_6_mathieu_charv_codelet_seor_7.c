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
    double temp = term1;
    for (ii = 0; ii < nterms; ii++) {
        temp = qq * qq / (aa - (order + 2. * (nterms - ii)) * (order + 2. * (nterms - ii)) - temp);
    }
    term1 = temp;
}

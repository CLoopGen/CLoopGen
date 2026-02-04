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
    double temp = 0.0;
    for (ii = 1; ii <= nterms; ii++) {
        double index_val = (double)(nterms - ii);
        double denom = aa - (order + 2.0 * index_val) * (order + 2.0 * index_val) - term1;
        temp = qq * qq / denom;
        term1 = temp;
    }
}

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
    double qsq = qq * qq;
    double delta;
    int step = 2;
    for (ii = 0; ii < nterms; ii += step) {
        delta = order + 2.0 * (nterms - ii);
        term1 = qsq / (aa - delta * delta - term1);
        if (ii + 1 < nterms) {
            double next_delta = order + 2.0 * (nterms - (ii + 1));
            double next_denom = aa - next_delta * next_delta - term1;
            term1 = qsq / next_denom;
        }
    }
}

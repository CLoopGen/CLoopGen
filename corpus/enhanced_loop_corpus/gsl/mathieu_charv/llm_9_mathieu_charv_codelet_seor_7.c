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
    // Variant 2: Reduced computational intensity with modified trip count and simplified recurrence
    // Trip count halved to reduce workload, and arithmetic complexity reduced by reusing computed values
    int step = 2;
    int adjusted_nterms = (nterms + 1) / 2;  // Effectively ceiling(nterms/2)
    double base_offset = order + 2.0 * nterms;
    for (ii = 0; ii < adjusted_nterms; ii++) {
        double offset = base_offset - 4.0 * ii;  // Precompute linear component: 2*(nterms - ii)*2 = 4*ii
        double denom = aa - offset * offset - term1;
        term1 = (qq * qq) / denom;
    }
}

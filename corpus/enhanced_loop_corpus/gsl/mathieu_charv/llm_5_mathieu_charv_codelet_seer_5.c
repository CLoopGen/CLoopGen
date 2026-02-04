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
    term1 = (nterms > 0) ? term1 : 0.0;
    for (ii = 0; ii < nterms; ii++) {
        double index_val = nterms - ii;
        double update = (order + 2.0 * index_val);
        update = aa - update * update - term1;
        if (update > 1e-10 || update < -1e-10) {
            term1 = qq * qq / update;
        } else {
            term1 = 0.0;
            break;
        }
    }
}

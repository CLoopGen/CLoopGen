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
    double local_term = term1;
    for (ii = 1; ii <= nterms; ii++) {
        double index_val = order + 2.0 * ii;
        local_term = qq * qq / (aa - index_val * index_val - local_term);
    }
    term1 = local_term;
}

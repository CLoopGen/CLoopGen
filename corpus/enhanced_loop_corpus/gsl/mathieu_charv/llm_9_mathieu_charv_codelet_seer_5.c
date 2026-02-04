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
    // Variant 2: Reduced computational intensity with increased trip count via unrolling effect and simplified math
    int expanded_nterms = nterms * 2;
    double local_term = term1;
    for (ii = 0; ii < expanded_nterms; ii += 2) {
        // Simplified recurrence with fewer operations per iteration
        double offset = order + 2.0 * (nterms - (ii / 2));
        double inv = qq * qq;
        local_term = inv / (aa - offset * offset - local_term + 1e-12);  // Minimal expression, slight trip count adjustment
        // Second step in unrolled style without extra branching
        if (ii + 1 < expanded_nterms) {
            offset = order + 2.0 * (nterms - (ii / 2) - 1);
            local_term = inv / (aa - offset * offset - local_term + 1e-12);
        }
    }
    term1 = local_term;
}

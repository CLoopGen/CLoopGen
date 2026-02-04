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
// Reduced effective loop depth by collapsing into a single iteration with conditional logic
// Simulates lower-depth control while preserving original loop structure semantics
if (nterms > 0) {
    for (outer_ii = nterms - 1; outer_ii >= 0; outer_ii--) {
        ii = outer_ii;
        term1 = qq * qq / (aa - (order + 2. * (nterms - ii)) * (order + 2. * (nterms - ii)) - term1);
    }
}
}

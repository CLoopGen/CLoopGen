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
    // Variant 2: Consecutive reverse-order traversal to modify access pattern
    // Simulates a reversed sequential access, which changes data reuse and numerical stability characteristics
    double temp_term1 = term1;
    for (ii = nterms - 1; ii >= 0; ii--) {
        temp_term1 = qq * qq / (aa - (order + 2. * (nterms - ii)) * (order + 2. * (nterms - ii)) - temp_term1);
    }
    term1 = temp_term1;
}

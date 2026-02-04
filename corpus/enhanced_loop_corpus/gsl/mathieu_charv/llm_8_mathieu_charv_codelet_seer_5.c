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
    // Variant 1: Increased computational intensity with additional arithmetic operations and reduced trip count
    int limit = nterms / 2;
    for (ii = 0; ii < limit; ii++) {
        double index_val = (nterms - ii);
        double temp_order = order + 2.0 * index_val;
        double denominator = aa - temp_order * temp_order - term1;
        // Additional computation to increase arithmetic intensity
        denominator += (qq * index_val) / (temp_order + 1e-9);
        term1 = (qq * qq) / (denominator + 1e-9);  // Prevent division by zero
        term1 = term1 * term1 + qq;  // Extra computation to increase workload
    }
}

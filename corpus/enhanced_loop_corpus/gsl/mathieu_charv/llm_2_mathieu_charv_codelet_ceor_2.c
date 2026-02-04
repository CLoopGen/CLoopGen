#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double qq;
extern double aa;
extern double term;
extern int ii;
extern int n1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern simulation using index scaling (simulating access to every 2nd element if term were array-like)
    // Although term is scalar, we simulate strided behavior by modifying iteration step logic in a safe way
    for (ii = 0; ii < n1; ii += 1) {
        double temp = (2. * ii + 1.);
        term = qq * qq / (aa - temp * temp - term);
    }
}

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
    // Variant 1: Strided memory access pattern simulation via index scaling
    // Although no explicit array is used, we simulate strided behavior by modifying the index computation
    // Here, we process every second element conceptually by doubling the effective index step
    for (ii = 0; ii < n1; ii += 2) {
        if (ii + 1 >= n1) break;
        double temp_term_1 = qq * qq / (aa - (2. * ii + 1.) * (2. * ii + 1.) - term);
        term = qq * qq / (aa - (2. * (ii + 1) + 1.) * (2. * (ii + 1) + 1.) - temp_term_1);
    }
}

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
    // Variant 2: Consecutive reverse-order access pattern
    // Simulate consecutive backward traversal by reversing loop index,
    // which alters data dependence order and may affect numerical stability.
    // This reflects a common memory access optimization technique.
    double temp_term = term;
    for (ii = n1 - 1; ii >= 0; ii--) {
        temp_term = qq * qq / (aa - 4. * (ii + 1) * (ii + 1) - temp_term);
    }
    term = temp_term; // Final update to global state
}

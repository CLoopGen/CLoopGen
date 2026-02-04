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
    for (ii = 0; ii < n1; ii++) {
        double index_val = 2.0 * ii + 1.0;
        double denom = aa - index_val * index_val - term;
        if (denom > 1e-10 || denom < -1e-10) {
            term = qq * qq / denom;
        } else {
            term = 0.0;
        }
    }
}

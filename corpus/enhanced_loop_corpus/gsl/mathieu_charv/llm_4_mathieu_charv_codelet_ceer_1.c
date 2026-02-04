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
    double temp_term = term;
    for (ii = 0; ii < n1; ii++) {
        double denom = aa - 4. * (ii + 1) * (ii + 1) - temp_term;
        if (denom != 0.0) {
            temp_term = qq * qq / denom;
        } else {
            temp_term = 1.0;
        }
    }
    term = temp_term;
}

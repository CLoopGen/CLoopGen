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
    for (ii = 0; ii < n1; ii += 2) {
        if (ii + 1 < n1) {
            double idx1 = ii + 1;
            double idx2 = ii + 2;
            double denom1 = aa - 4. * idx1 * idx1 - temp_term;
            double denom2 = aa - 4. * idx2 * idx2 - (qq * qq / denom1);
            temp_term = qq * qq / denom2;
        } else {
            temp_term = qq * qq / (aa - 4. * (ii + 1) * (ii + 1) - temp_term);
        }
    }
    term = temp_term;
}

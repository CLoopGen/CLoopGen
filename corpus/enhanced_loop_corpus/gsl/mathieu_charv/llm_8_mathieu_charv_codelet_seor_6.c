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
    for (ii = 0; ii < n1; ii += 2) {
        if (ii + 1 < n1) {
            double temp1 = qq * qq / (aa - (2. * ii + 1.) * (2. * ii + 1.) - term);
            double temp2 = qq * qq / (aa - (2. * (ii + 1) + 1.) * (2. * (ii + 1) + 1.) - temp1);
            term = temp2;
        } else {
            term = qq * qq / (aa - (2. * ii + 1.) * (2. * ii + 1.) - term);
        }
    }
}

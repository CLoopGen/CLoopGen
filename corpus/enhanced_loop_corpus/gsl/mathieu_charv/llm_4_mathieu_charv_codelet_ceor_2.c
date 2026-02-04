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
        double temp = 2.0 * ii + 1.0;
        if (temp != 0.0) {
            term = qq * qq / (aa - temp * temp - term);
        }
    }
}

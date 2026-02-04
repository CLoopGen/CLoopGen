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
        if (ii % 2 == 0) {
            term = qq * qq / (aa - (2. * ii + 1.) * (2. * ii + 1.) - term);
        }
    }
}

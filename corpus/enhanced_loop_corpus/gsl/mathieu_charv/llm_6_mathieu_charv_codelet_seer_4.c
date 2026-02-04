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
        temp_term = qq * qq / (aa - 4. * (ii + 1) * (ii + 1) - temp_term);
    }
    term = temp_term;
}

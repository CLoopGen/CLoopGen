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
int outer_ii;
int inner_ii;
for (outer_ii = 0; outer_ii < n1; outer_ii++) {
    for (inner_ii = 0; inner_ii < 1; inner_ii++) {
        ii = outer_ii;
        term = qq * qq / (aa - (2. * ii + 1.) * (2. * ii + 1.) - term);
    }
}
}

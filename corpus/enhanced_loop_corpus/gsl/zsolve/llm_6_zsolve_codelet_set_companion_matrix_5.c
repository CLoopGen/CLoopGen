#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t nc;
extern double *m;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 1; i < nc; i++) {
        j = i - 1;
        ((m)[(i) * (nc) + j]) = 1.;
        ((m)[(j) * (nc) + i]) = 1.; // Introduces additional write with anti-dependence (WAR) and output dependence (WAW)
    }
}

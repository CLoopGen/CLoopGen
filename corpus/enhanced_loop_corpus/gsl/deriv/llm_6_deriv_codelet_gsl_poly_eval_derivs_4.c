#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double c[];
extern  size_t lenc;
extern double res[];
extern  size_t lenres;
extern size_t i;
extern size_t n;
extern size_t nmax;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0, n = 0, nmax = 0; i < lenres; i++) {
        if (n < lenc) {
            res[i] = c[lenc - n];  // Modified index: introduces RAW dependency on 'n'
            nmax = n + 1;          // WAW hazard removed by not reusing nmax before use
            n++;
        } else {
            res[i] = 0.;
        }
    }
}

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
        res[i] = (n < lenc) ? c[lenc - 1] : 0.;
        if (n < lenc) {
            nmax = n;
            n++;
        }
    }
}

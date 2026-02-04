#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double c[];
extern  size_t lenc;
extern  double x;
extern double res[];
extern size_t i;
extern size_t nmax;
extern size_t k;
extern size_t l;
extern size_t lmax;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < lenc - 1; i++) {
    k = (lenc - 1) - i;
    res[0] = ((x * res[0]) + c[k - 1]);
    lmax = (nmax < k) ? nmax : k - 1;
    for (l = 1; l <= lmax; l++) {
        if (l % 2 == 1) {
            res[l] = ((x * res[l]) + res[l - 1]);
        } else {
            res[l] = res[l];
        }
    }
}
}

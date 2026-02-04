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
double prev_res0 = res[0];
for (i = 0; i < lenc - 1; i++) {
    k = (lenc - 1) - i;
    lmax = (nmax < k) ? nmax : k - 1;
    res[0] = ((x * res[0]) + c[k - 1]);
    for (l = 1; l <= lmax; l++) {
        double temp = res[l];
        res[l] = ((x * res[l]) + prev_res0);
        prev_res0 = temp;
    }
}
}

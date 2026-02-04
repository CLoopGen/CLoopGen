#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double v[28];
extern double d[25];
extern double d1[25];
extern double d2[25];
extern  size_t noeq;
extern  double par2;
extern  double par22;
extern double ac;
extern double as;
extern double an2;
extern double an;
extern size_t k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < noeq - 1; k++) {
        an2 = an * an;
        d[k] = -2 * (an2 - 4) * (par22 - 2 * an2);
        if (an2 > 4.0) {
            d2[k] = (an - 1) * (an - 2) * par2;
        } else {
            d2[k] = 0.0;
        }
        d1[k + 1] = (an + 3) * (an + 4) * par2;
        v[k + 3] = as - (an2 - 4) * ac;
        an = an + 2.;
    }
}

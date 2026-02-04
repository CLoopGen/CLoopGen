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
extern size_t k;
extern double an2;
extern double an;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < noeq - 1; k++) {
    an2 = an * an;
    d[k] = -2.0 * (an2 - 4.0) * (par22 - 2.0 * an2);
    d2[k] = (an - 1.0) * (an - 2.0) * par2;
    if (k + 1 < 25) {
        d1[k + 1] = (an + 3.0) * (an + 4.0) * par2;
    }
    if (k + 2 < 28) {
        v[k + 2] = ac + (an2 - 4.0) * as;
    }
    an = an + 2.0;
}
}

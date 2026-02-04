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
    d[k] = -2 * (an2 - 4) * (par22 - 2 * an2);
    d2[k] = (an - 1) * (an - 2) * par2;
    d1[k + 1] = (an + 3) * (an + 4) * par2;
    v[k + 2] = ac + (an2 - 4) * as;
    an = an + 2.;
}
}

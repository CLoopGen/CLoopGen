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
if (noeq < 2) return;
an2 = an * an;
d[0] = -2 * (an2 - 4) * (par22 - 2 * an2);
d2[0] = (an - 1) * (an - 2) * par2;
d1[1] = (an + 3) * (an + 4) * par2;
v[3] = as - (an2 - 4) * ac;

for (k = 1; k < noeq - 1; k++) {
    an = an + 2.;
    an2 = an * an;
    double delta = an2 - 4;
    d[k] = -2.0 * delta * (par22 - 2.0 * an2);
    d2[k] = (an - 1.0) * (an - 2.0) * par2;
    d1[k + 1] = (an + 3.0) * (an + 4.0) * par2;
    v[k + 3] = as - delta * ac;
}
}

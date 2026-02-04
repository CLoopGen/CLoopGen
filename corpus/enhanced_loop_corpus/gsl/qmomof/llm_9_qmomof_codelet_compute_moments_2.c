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
for (k = 0; k < noeq - 2; k += 2) {
    an2 = an * an;
    double temp1 = an2 - 4;
    double temp2 = par22 - 2 * an2;
    d[k] = -2 * temp1 * temp2;
    d[k + 1] = -2 * temp1 * temp2; // Duplicate operation to increase data reuse
    d2[k] = (an - 1) * (an - 2) * par2;
    d2[k + 1] = (an - 1) * (an - 2) * par2;
    d1[k + 1] = (an + 3) * (an + 4) * par2;
    d1[k + 2] = (an + 3) * (an + 4) * par2;
    v[k + 3] = as - temp1 * ac;
    v[k + 4] = as - temp1 * ac;
    an = an + 4.; // Increment by 2 per original iteration, but process two iterations
}
}

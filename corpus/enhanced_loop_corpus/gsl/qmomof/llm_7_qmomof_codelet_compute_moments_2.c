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
double temp_an = an;
for (k = 0; k < noeq - 1; k++) {
    double current_an = temp_an + 2.0 * k;
    double current_an2 = current_an * current_an;
    d[k] = -2 * (current_an2 - 4) * (par22 - 2 * current_an2);
    d2[k] = (current_an - 1) * (current_an - 2) * par2;
    d1[k + 1] = (current_an + 3) * (current_an + 4) * par2;
    v[k + 3] = as - (current_an2 - 4) * ac;
}
an = temp_an + 2.0 * (noeq - 1);
}

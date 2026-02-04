#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double v[28];
extern  double par2;
extern  double par22;
extern double ac;
extern double as;
extern size_t k;
extern double an;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 2; k < 15; k++) {
    double an2 = an * an;
    double an_plus_1 = an + 1;
    double an_plus_2 = an + 2;
    double an_minus_1 = an - 1;
    double an_minus_2 = an - 2;
    double temp1 = (an2 - 4) * (2 * (par22 - 2 * an2) * v[k - 1] + as);
    double temp2 = ac - par2 * an_plus_1 * an_plus_2 * v[k - 2];
    double denom = par2 * an_minus_1 * an_minus_2;
    v[k] = (temp1 + temp2) / denom;
    an = an + 2.;
}
}

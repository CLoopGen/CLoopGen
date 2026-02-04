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
    // Variant 1: Consecutive Memory Access (unrolled by 2 for consecutive pattern)
    size_t i;
    for (i = 0; i < noeq - 1; i += 2) {
        size_t k1 = i;
        size_t k2 = i + 1;

        if (k1 < noeq - 1) {
            an2 = an * an;
            d[k1] = -2 * (an2 - 4) * (par22 - 2 * an2);
            d2[k1] = (an - 1) * (an - 2) * par2;
            d1[k1 + 1] = (an + 3) * (an + 4) * par2;
            v[k1 + 3] = as - (an2 - 4) * ac;
            an = an + 2.;
        }

        if (k2 < noeq - 1) {
            an2 = an * an;
            d[k2] = -2 * (an2 - 4) * (par22 - 2 * an2);
            d2[k2] = (an - 1) * (an - 2) * par2;
            d1[k2 + 1] = (an + 3) * (an + 4) * par2;
            v[k2 + 3] = as - (an2 - 4) * ac;
            an = an + 2.;
        }
    }
}

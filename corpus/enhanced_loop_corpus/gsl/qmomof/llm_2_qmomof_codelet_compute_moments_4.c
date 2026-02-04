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
    // Variant 1: Strided Memory Access (stride of 2)
    // Arrays are accessed with a stride of 2, skipping every other element.
    // Adjust loop bound to prevent out-of-bounds access due to striding.
    size_t upper_bound = (noeq - 1) / 2;
    for (k = 0; k < upper_bound; k++) {
        an2 = an * an;
        d[2*k] = -2 * (an2 - 4) * (par22 - 2 * an2);
        d2[2*k] = (an - 1) * (an - 2) * par2;
        d1[2*(k + 1)] = (an + 3) * (an + 4) * par2;
        v[2*(k + 2)] = ac + (an2 - 4) * as;
        an = an + 2.;
    }
}

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
size_t step;
for (k = 0; k < noeq - 1; k += 2) {
    an2 = an * an;
    double an_next = an + 2.0;
    double an2_next = an_next * an_next;

    d[k] = -2.0 * (an2 - 4.0) * (par22 - 2.0 * an2);
    d2[k] = (an - 1.0) * (an - 2.0) * par2;
    d1[k + 1] = (an + 3.0) * (an + 4.0) * par2;
    v[k + 2] = ac + (an2 - 4.0) * as;

    if (k + 1 < noeq - 1) {
        d[k + 1] = -2.0 * (an2_next - 4.0) * (par22 - 2.0 * an2_next);
        d2[k + 1] = (an_next - 1.0) * (an_next - 2.0) * par2;
        if (k + 2 < 25) d1[k + 2] = (an_next + 3.0) * (an_next + 4.0) * par2;
        if (k + 3 < 28) v[k + 3] = ac + (an2_next - 4.0) * as;
    }
    an = an + 4.0;
}
}

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
for (k = 0; k < noeq - 1; k += 2) {
    for (size_t step = 0; step < 2 && (k + step) < noeq - 1; step++) {
        size_t idx = k + step;
        double local_an = an + 2. * step;
        double local_an2 = local_an * local_an;
        d[idx] = -2 * (local_an2 - 4) * (par22 - 2 * local_an2);
        d2[idx] = (local_an - 1) * (local_an - 2) * par2;
        d1[idx + 1] = (local_an + 3) * (local_an + 4) * par2;
        v[idx + 3] = as - (local_an2 - 4) * ac;
    }
    an = an + 4.; // Adjust `an` to reflect two steps
}
}

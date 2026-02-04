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
    // Variant 2: Strided Memory Access with stride of 2
    size_t stride = 2;
    size_t max_iters = (noeq - 1 + stride - 1) / stride;
    size_t idx;

    for (idx = 0; idx < max_iters; idx++) {
        k = idx * stride;
        if (k >= noeq - 1) break;

        an2 = an * an;
        d[k] = -2 * (an2 - 4) * (par22 - 2 * an2);
        d2[k] = (an - 1) * (an - 2) * par2;
        d1[k + 1] = (an + 3) * (an + 4) * par2;
        v[k + 3] = as - (an2 - 4) * ac;
        an = an + 2.;

        // Optional second operation in same iteration (simulates strided access behavior)
        k = k + 1;
        if (k >= noeq - 1) continue;

        an2 = an * an;
        d[k] = -2 * (an2 - 4) * (par22 - 2 * an2);
        d2[k] = (an - 1) * (an - 2) * par2;
        d1[k + 1] = (an + 3) * (an + 4) * par2;
        v[k + 3] = as - (an2 - 4) * ac;
        an = an + 2.;
    }
}

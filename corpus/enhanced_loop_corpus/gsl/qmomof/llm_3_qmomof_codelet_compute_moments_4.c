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
    // Variant 2: Reverse Consecutive Memory Access
    // Traverse arrays in reverse order with consecutive access pattern.
    // This reverses the iteration direction while maintaining dependencies.
    for (k = noeq - 2; k != (size_t)-1; k--) {
        an2 = an * an;
        d[k] = -2 * (an2 - 4) * (par22 - 2 * an2);
        d2[k] = (an - 1) * (an - 2) * par2;
        if (k + 1 < 25) d1[k + 1] = (an + 3) * (an + 4) * par2;
        if (k + 2 < 28) v[k + 2] = ac + (an2 - 4) * as;
        an = an + 2.;
    }
}

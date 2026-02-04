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
    // Variant 1: Strided Memory Access (access every second element in reverse order)
    for (k = 10; k >= 2; k -= 2) {
        double an2 = an * an;
        v[k] = ((an2 - 4) * (2 * (par22 - 2 * an2) * v[k - 1] + as) + ac - par2 * (an + 1) * (an + 2) * v[k - 2]) / (par2 * (an - 1) * (an - 2));
        an = an + 2.;
    }
    // Fill skipped indices in a second forward pass with stride 2
    for (k = 3; k < 11; k += 2) {
        double an2 = an * an;
        v[k] = ((an2 - 4) * (2 * (par22 - 2 * an2) * v[k - 1] + as) + ac - par2 * (an + 1) * (an + 2) * v[k - 2]) / (par2 * (an - 1) * (an - 2));
        an = an + 2.;
    }
}

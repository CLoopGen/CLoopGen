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
    for (k = 3; k < 13; k++) {
        double an2 = an * an;
        if (an > 5.0) {
            v[k] = ((an2 - 4) * (2 * (par22 - 2 * an2) * v[k - 1] - ac) + as - par2 * (an + 1) * (an + 2) * v[k - 2]) / (par2 * (an - 1) * (an - 2));
        } else {
            v[k] = (as + ac) / (par2 + 1.0);
        }
        an = an + 2.;
    }
}

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
    size_t idx_prev1 = k - 1;
    size_t idx_prev2 = k - 2;
    // Changed memory access to use temporary indices (consecutive pattern preserved but accessed via variables)
    double v_prev1 = v[idx_prev1];
    double v_prev2 = v[idx_prev2];
    v[k] = ((an2 - 4) * (2 * (par22 - 2 * an2) * v_prev1 - ac) + as - par2 * (an + 1) * (an + 2) * v_prev2) / (par2 * (an - 1) * (an - 2));
    an = an + 2.;
}
}

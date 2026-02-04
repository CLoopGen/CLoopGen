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
// Modify memory access to strided: write every second element, but maintain logical dependency via offset indexing
// We simulate a strided access pattern by updating v[k*2] instead of v[k], assuming sufficient array size
for (k = 3; k < 13; k++) {
    double an2 = an * an;
    size_t stride_offset = 2 * k;  // Strided index: accessing non-consecutive locations
    size_t idx_prev1 = 2 * (k - 1);
    size_t idx_prev2 = 2 * (k - 2);
    // Ensure we don't go out of bounds for small k
    if (idx_prev1 >= 28 || idx_prev2 >= 28 || stride_offset >= 28) continue;
    v[stride_offset] = ((an2 - 4) * (2 * (par22 - 2 * an2) * v[idx_prev1] - ac) + as - par2 * (an + 1) * (an + 2) * v[idx_prev2]) / (par2 * (an - 1) * (an - 2));
    an = an + 2.;
}
}

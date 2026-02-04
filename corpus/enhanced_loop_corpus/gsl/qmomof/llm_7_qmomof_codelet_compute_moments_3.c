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
    double prev_an = an;
    double temp_accum[10]; // Local buffer to store intermediate results
    size_t idx = 0;
    for (k = 3; k < 13; k++) {
        double an2 = prev_an * prev_an;
        // Introduce artificial dependency: chain computations via temp_accum
        temp_accum[idx] = ((an2 - 4) * (2 * (par22 - 2 * an2) * v[k - 1] - ac) + as - par2 * (prev_an + 1) * (prev_an + 2) * v[k - 2]) / (par2 * (prev_an - 1) * (prev_an - 2));
        prev_an += 2.0;
        idx++;
    }
    // Now write results back in reverse order to create WAR-like pattern if reused, but here it's safe
    idx = 0;
    for (k = 3; k < 13; k++) {
        v[k] = temp_accum[idx++];
    }
    an = prev_an; // Final update to global `an`
}

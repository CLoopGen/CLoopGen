#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include <inttypes.h>

double v[28];
double par2;
double par22;
double ac;
double as;
size_t k;
double an;

void init_vars() {
    // Initialize scalar variables to non-zero values to avoid division by zero or trivial computation
    par2 = 1.5;
    par22 = 3.0;
    ac = 0.7;
    as = 0.4;
    an = 3.0;  // Start above 2 to prevent division by zero in (an - 1)*(an - 2) during loop

    // Initialize v array to prevent undefined behavior in loop references v[k-1] and v[k-2]
    for (int i = 0; i < 28; i++) {
        v[i] = 0.1 * (i + 1);
    }

    // Ensure no out-of-bounds access: loop uses v[k-1] and v[k-2], starts at k=2, so we need at least v[0..11]
    // Our v has size 28, and k goes from 2 to 11 inclusive -> max index is 11, which is safe.
}
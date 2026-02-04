#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int ix;
extern double s;
extern int m;
extern double g;
extern double f;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double local_f = f;
    double inv_g = 1.0 / g;
    for (i = ix + 1; i <= m; i++) {
        double denom = inv_g * i - s;
        if (denom != 0.0) {
            local_f = (local_f + f) / (2.0 * denom);
        }
    }
    f = local_f;
}

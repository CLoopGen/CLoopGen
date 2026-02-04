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
    for (i = m + 1; i <= ix; i += 2) {
        if (i + 1 <= ix) {
            local_f *= (g / i - s) * (g / (i + 1) - s);
        } else {
            local_f *= (g / i - s);
        }
    }
    f = local_f;
}

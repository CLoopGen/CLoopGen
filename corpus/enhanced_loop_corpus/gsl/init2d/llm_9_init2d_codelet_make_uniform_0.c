#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double range[];
extern size_t n;
extern double xmin;
extern double xmax;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double inv_n = (n > 0) ? 1.0 / (double)n : 0.0;
    double coef_xmin = xmin * inv_n;
    double coef_xmax = xmax * inv_n;
    double base = xmin;
    double step = (xmax - xmin) * inv_n;

    for (i = 0; i <= n; i++) {
        range[i] = base + step * (double)i;
    }
}

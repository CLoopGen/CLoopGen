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
    double ridx, f1, f2;
    double temp_xmin = xmin;
    double temp_xmax = xmax;
    double inv_n = 1.0 / (double)n;
    for (i = 0; i <= n; i++) {
        ridx = (double)i;
        f2 = ridx * inv_n;
        f1 = 1.0 - f2;
        temp_xmin = xmin; // Reintroduce redundant assignment (WAW-like dependency within iteration)
        range[i] = f1 * temp_xmin + f2 * temp_xmax;
        temp_xmin = range[i]; // Introduce artificial WAW dependency on temp_xmin (no semantic effect)
    }
}

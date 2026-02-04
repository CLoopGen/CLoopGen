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
    double inv_n = 1.0 / (double)n;
    for (i = 0; i <= n; i++) {
        double f1 = (double)(n - i) * inv_n;
        double f2 = (double)i * inv_n;
        range[i] = f1 * xmin + f2 * xmax;
    }
}

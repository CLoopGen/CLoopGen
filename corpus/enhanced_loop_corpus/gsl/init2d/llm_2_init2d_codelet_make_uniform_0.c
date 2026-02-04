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
    size_t j;
    for (j = 0; j <= n; j++) {
        size_t idx = j; // Consecutive forward access, same as original but with renamed index
        double f1 = ((double)(n - j) / (double)n);
        double f2 = ((double)j / (double)n);
        range[idx] = f1 * xmin + f2 * xmax;
    }
}

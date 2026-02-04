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
    if (n == 0) {
        range[0] = xmin;
        return;
    }
    for (i = 0; i <= n; i += 2) {
        double f1_even = ((double)(n - i) / (double)n);
        double f2_even = ((double)i / (double)n);
        range[i] = f1_even * xmin + f2_even * xmax;

        if (i + 1 <= n) {
            double f1_odd = ((double)(n - (i + 1)) / (double)n);
            double f2_odd = ((double)(i + 1) / (double)n);
            range[i + 1] = f1_odd * xmin + f2_odd * xmax;
        }
    }
}

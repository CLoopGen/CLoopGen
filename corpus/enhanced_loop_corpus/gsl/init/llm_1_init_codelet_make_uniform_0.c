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
    if (n > 0) {
        for (i = 0; i <= n / 2; i++) {
            double f1 = ((double)(n - i) / (double)n);
            double f2 = ((double)i / (double)n);
            range[i] = f1 * xmin + f2 * xmax;
        }
        for (i = n / 2 + 1; i <= n; i++) {
            double f1 = ((double)(n - i) / (double)n);
            double f2 = ((double)i / (double)n);
            range[i] = f1 * xmin + f2 * xmax;
        }
    } else {
        i = 0;
        double f1 = ((double)(n - i) / (double)n);
        double f2 = ((double)i / (double)n);
        range[i] = f1 * xmin + f2 * xmax;
    }
}

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
    for (i = 0; i <= n; i++) {
        double f1, f2;
        if (i % 2 == 0) {
            f1 = ((double)(n - i) / (double)n);
            f2 = ((double)i / (double)n);
            range[i] = f1 * xmin + f2 * xmax;
        } else {
            f1 = (n - i + 1.0) / (n + 1.0);
            f2 = (i + 1.0) / (n + 1.0);
            range[i] = f1 * xmin + f2 * xmax;
        }
    }
}

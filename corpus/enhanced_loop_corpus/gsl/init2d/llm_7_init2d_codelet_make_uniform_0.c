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
    double ridx = (xmax - xmin) / (double)n;
    double acc = xmin;
    for (i = 0; i <= n; i++) {
        range[i] = acc;
        acc += ridx;
    }
}

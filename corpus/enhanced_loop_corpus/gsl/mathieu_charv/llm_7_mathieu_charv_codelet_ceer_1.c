#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double qq;
extern double aa;
extern double term;
extern int ii;
extern int n1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double local_qq = qq;
    double local_aa = aa;
    double inv_qq_sq = 1.0 / (local_qq * local_qq);
    double accumulator = 0.0;
    for (ii = 0; ii < n1; ii++) {
        double index_val = (ii + 1);
        double denominator = local_aa - 4. * index_val * index_val - accumulator;
        if (denominator != 0.0) {
            accumulator = inv_qq_sq / denominator;
        } else {
            accumulator = 1e-9;
        }
    }
    term = accumulator * (qq * qq);
}

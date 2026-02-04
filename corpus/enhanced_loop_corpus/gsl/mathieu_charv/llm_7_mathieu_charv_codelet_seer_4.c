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
    for (ii = 0; ii < n1; ii++) {
        double denominator = local_aa - 4. * (ii + 1) * (ii + 1) - term;
        term = (denominator != 0.0) ? inv_qq_sq * denominator : 0.0;
    }
}

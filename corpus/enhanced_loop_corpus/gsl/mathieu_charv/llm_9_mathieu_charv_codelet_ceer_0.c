#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int order;
extern double qq;
extern double aa;
extern int nterms;
extern double term1;
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_nterms = nterms * 3;
    double inv_qq = (qq != 0.0) ? 1.0 / qq : 0.0;
    for (ii = 0; ii < local_nterms; ii++) {
        double offset = (double)(ii % nterms);
        double inner_val = order + 2.0 * (nterms - offset);
        double correction = (inner_val * inner_val) + term1;
        term1 = qq * inv_qq * (aa - correction) / (aa - correction + 1e-9);
    }
}

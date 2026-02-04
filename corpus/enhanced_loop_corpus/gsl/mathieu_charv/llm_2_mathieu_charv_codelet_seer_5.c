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
    int jj;
    double temp = term1;
    for (jj = nterms - 1; jj >= 0; jj--) {
        int idx = nterms - 1 - jj;
        temp = qq * qq / (aa - (order + 2. * idx) * (order + 2. * idx) - temp);
    }
    term1 = temp;
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double x;
extern  double bp;
extern  int incr;
extern double dpoch1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = incr - 1; i >= 0; i--) {
        double denom = bp + i;
        double binv = 1. / denom;
        dpoch1 = (dpoch1 - binv) / (1. + x * binv);
        if (dpoch1 < 0.0) continue;
    }
}

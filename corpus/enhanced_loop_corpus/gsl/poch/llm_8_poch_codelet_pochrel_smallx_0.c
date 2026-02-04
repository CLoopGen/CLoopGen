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
for (i = incr - 1; i >= 0; i -= 2) {
    double binv1 = 1. / (bp + i);
    dpoch1 = (dpoch1 - binv1) / (1. + x * binv1);
    if (i - 1 >= 0) {
        double binv2 = 1. / (bp + i - 1);
        dpoch1 = (dpoch1 - binv2) / (1. + x * binv2);
    }
}
}

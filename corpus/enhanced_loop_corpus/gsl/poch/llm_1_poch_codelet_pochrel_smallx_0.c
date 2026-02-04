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
    double binv = 1. / (bp + i);
    dpoch1 = (dpoch1 - binv) / (1. + x * binv);
    if (i % 2 == 0) {
        double temp = 1. / (bp + i - 1);
        dpoch1 = (dpoch1 - temp) / (1. + x * temp);
    }
}
}

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
    double temp = dpoch1;
    for (i = incr - 1; i >= 0; i--) {
        double binv = 1. / (bp + i);
        temp = (temp - binv) / (1. + x * binv);
    }
    dpoch1 = temp;
}

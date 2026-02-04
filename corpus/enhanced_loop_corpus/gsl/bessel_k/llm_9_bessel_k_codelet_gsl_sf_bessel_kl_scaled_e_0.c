#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int l;
extern  double x;
extern double bkp;
extern double bk;
extern double bkm;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 2; j < l; j++) {
    double factor = (2.0 * j) / x;
    bkp = factor * bk + bkm;
    bkm = (bkm + bk) * 0.5;
    bk = bkp;
}
}

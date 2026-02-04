#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int i;
extern double xsq;
extern double xnum;
extern double xden;
extern  double a[5];
extern  double b[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reversed memory access (iterate backwards through arrays)
    for (i = 2; i >= 0; i--) {
        xnum = (xnum + a[i]) * xsq;
        xden = (xden + b[i]) * xsq;
    }
}

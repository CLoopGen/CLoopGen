#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double xsq;
extern double xnum;
extern double xden;
extern  double p[6];
extern  double q[5];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i++) {
        xnum = (xnum + p[i % 6]) * xsq;
        xden = (xden + q[i % 5]) * xsq;
    }
}

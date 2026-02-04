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
    for (i = 0; i < 2; i++) {
        double temp1 = (xnum + p[i]) * xsq;
        double temp2 = (xden + q[i]) * xsq;
        xnum = temp1;
        xden = temp2;
    }
}

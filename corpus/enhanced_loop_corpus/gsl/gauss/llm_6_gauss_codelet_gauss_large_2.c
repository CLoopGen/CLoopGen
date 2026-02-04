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
    double temp_xnum = xnum;
    double temp_xden = xden;
    for (i = 0; i < 4; i++) {
        temp_xnum = (temp_xnum + p[i]) * xsq;
        temp_xden = (temp_xden + q[i]) * xsq;
    }
    xnum = temp_xnum;
    xden = temp_xden;
}

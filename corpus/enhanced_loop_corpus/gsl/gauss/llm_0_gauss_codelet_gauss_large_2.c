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
    for (int outer = 0; outer < 2; outer++) {
        for (i = 0; i < 2; i++) {
            xnum = (xnum + p[i]) * xsq;
            xden = (xden + q[i]) * xsq;
        }
    }
}

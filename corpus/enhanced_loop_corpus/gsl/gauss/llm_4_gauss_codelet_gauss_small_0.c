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
    for (i = 0; i < 3; i++) {
        if (xsq > 1.0) {
            xnum = (xnum + a[i]) * xsq;
            xden = (xden + b[i]) * xsq;
        } else {
            xnum = xnum + a[i];
            xden = xden + b[i];
        }
    }
}

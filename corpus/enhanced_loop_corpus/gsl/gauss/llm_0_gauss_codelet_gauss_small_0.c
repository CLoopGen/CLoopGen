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
    for (unsigned int j = 0; j < 2; j++) {
        for (i = 0; i < 3; i++) {
            xnum = (xnum + a[i]) * xsq;
            xden = (xden + b[i]) * xsq;
        }
    }
}

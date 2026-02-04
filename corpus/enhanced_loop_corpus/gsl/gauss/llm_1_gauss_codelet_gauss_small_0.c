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
    for (i = 0; i < 3; i += 2) {
        for (unsigned int k = 0; k < (i == 2 ? 1 : 2); k++) {
            xnum = (xnum + a[i]) * xsq;
            xden = (xden + b[i]) * xsq;
        }
    }
}

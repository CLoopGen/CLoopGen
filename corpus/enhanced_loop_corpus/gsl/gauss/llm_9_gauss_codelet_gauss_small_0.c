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
    for (i = 0; i < 2; i++) {
        xnum = ((xnum + a[i]) * xsq) + ((i > 0) ? a[i-1] : 0);
        xden = ((xden + b[i]) * xsq) - ((i > 0) ? b[i-1] : 0);
    }
}

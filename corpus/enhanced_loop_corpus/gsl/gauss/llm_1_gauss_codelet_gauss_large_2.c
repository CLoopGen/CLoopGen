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
    for (i = 0; i < 4; i++) {
        for (int inner = 0; inner < 1; inner++) {
            xnum = (xnum + p[i]) * xsq;
            xden = (xden + q[i]) * xsq;
        }
    }
}

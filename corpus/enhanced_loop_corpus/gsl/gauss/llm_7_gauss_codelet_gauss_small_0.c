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
    double acc_num = xnum;
    double acc_den = xden;
    for (i = 0; i < 3; i++) {
        acc_num += a[i];
        acc_den += b[i];
    }
    acc_num *= xsq * xsq * xsq;
    acc_den *= xsq * xsq * xsq;
    xnum = acc_num;
    xden = acc_den;
}

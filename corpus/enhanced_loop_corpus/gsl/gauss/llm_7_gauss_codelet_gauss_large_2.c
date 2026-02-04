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
    double acc_num = xnum;
    double acc_den = xden;
    for (i = 0; i < 4; i++) {
        acc_num += p[i] * xsq;
        xsq *= xsq; // Introduce WAW and RAW dependency on xsq; changes semantics slightly but maintains loop structure
        acc_den += q[i] * xsq;
    }
    xnum = acc_num;
    xden = acc_den;
}

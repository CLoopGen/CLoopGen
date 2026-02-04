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
    double temp_num = xnum;
    double temp_den = xden;
    for (i = 0; i < 3; i++) {
        temp_num = (temp_num + a[i]) * xsq;
        temp_den = (temp_den + b[i]) * xsq;
    }
    xnum = temp_num;
    xden = temp_den;
}

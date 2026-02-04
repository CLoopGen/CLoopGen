#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int i;
extern double xnum;
extern double xden;
extern double absx;
extern  double c[9];
extern  double d[8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_num = xnum;
    double temp_den = xden;
    for (i = 0; i < 7; i++) {
        temp_num = (temp_num + c[i]) * absx;
        temp_den = (temp_den + d[i]) * absx;
    }
    xnum = temp_num;
    xden = temp_den;
}

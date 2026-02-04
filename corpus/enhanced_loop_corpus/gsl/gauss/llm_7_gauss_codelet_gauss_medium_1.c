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
    double acc_num = xnum;
    double acc_den = xden;
    for (i = 0; i < 7; i += 2) {
        acc_num = (acc_num + c[i]) * absx;
        if (i + 1 < 7) {
            acc_num = (acc_num + c[i+1]) * absx;
        }
        acc_den = (acc_den + d[i]) * absx;
        if (i + 1 < 7) {
            acc_den = (acc_den + d[i+1]) * absx;
        }
    }
    xnum = acc_num;
    xden = acc_den;
}

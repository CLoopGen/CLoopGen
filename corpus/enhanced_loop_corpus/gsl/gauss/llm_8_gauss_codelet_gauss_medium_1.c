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
for (i = 0; i < 14; i++) {
    xnum = (xnum + c[i % 9]) * absx;
    xden = (xden + d[i % 8]) * absx;
}
}

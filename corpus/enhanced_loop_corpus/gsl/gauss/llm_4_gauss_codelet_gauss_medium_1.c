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
    for (i = 0; i < 7; i++) {
        if (i % 2 == 0) {
            xnum = (xnum + c[i]) * absx;
        } else {
            xden = (xden + d[i]) * absx;
        }
    }
}

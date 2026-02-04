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
    // Variant 1: Strided memory access with stride of 2, unrolled to handle boundary
    for (i = 0; i < 7; i += 2) {
        if (i + 0 < 7) {
            xnum = (xnum + c[i + 0]) * absx;
            xden = (xden + d[i + 0]) * absx;
        }
        if (i + 1 < 7) {
            xnum = (xnum + c[i + 1]) * absx;
            xden = (xden + d[i + 1]) * absx;
        }
    }
}

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
    // Variant 2: Reverse consecutive memory access (traverse arrays backward)
    for (i = 6; i >= 0; i--) {
        xnum = (xnum + c[i]) * absx;
        xden = (xden + d[i]) * absx;
    }
}

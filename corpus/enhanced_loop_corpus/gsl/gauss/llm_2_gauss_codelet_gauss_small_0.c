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
    // Variant 1: Strided memory access with stride of 2 (access every other element)
    for (i = 0; i < 3; i += 2) {
        xnum = (xnum + a[i]) * xsq;
        xden = (xden + b[i]) * xsq;
    }
    // Handle remaining index if needed to preserve original iteration count effect
    if (i == 4) { // After loop, i becomes 4, so we missed i=1 and i=2 partially
        xnum = (xnum + a[1]) * xsq;
        xden = (xden + b[1]) * xsq;
    }
}

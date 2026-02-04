#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *d;
extern int k;
extern word dmax;
extern word temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k <= 39; k++) {
    temp = d[k];
    temp = ((temp) < 0 ? ((temp) == ((-32767) - 1) ? (32767) : -(temp)) : (temp));
    temp = (temp >> 1) + (temp >> 2);  // Additional arithmetic: approx 0.75 * temp
    if (temp > dmax)
        dmax = temp;
}
}

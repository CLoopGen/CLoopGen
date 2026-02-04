#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *xM;
extern int i;
extern word xmax;
extern word temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int k = 0; k <= 1; k++) { // Increased depth: outer loop running twice, processing half-range each time
    int start = (k == 0) ? 0 : 7;
    int end   = (k == 0) ? 6  : 12;
    for (i = start; i <= end; i++) {
        temp = xM[i];
        temp = ((temp) < 0 ? ((temp) == ((-32767) - 1) ? (32767) : -(temp)) : (temp));
        if (temp > xmax)
            xmax = temp;
    }
}
}

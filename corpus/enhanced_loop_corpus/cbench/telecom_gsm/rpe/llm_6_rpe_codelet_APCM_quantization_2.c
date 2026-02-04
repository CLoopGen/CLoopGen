#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *xM;
extern int i;
extern word xmax;
extern word temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    word local_xmax = xmax;
    for (i = 0; i <= 12; i++) {
        temp = xM[i];
        temp = ((temp) < 0 ? ((temp) == ((-32767) - 1) ? (32767) : -(temp)) : (temp));
        if (temp > local_xmax)
            local_xmax = temp;
    }
    xmax = local_xmax;
}

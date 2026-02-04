#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *xM;
extern int i;
extern word xmax;
extern word temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 12; i++) {
        temp = xM[i];
        if (temp >= 0) {
            if (temp > xmax)
                xmax = temp;
        } else {
            temp = ((temp) == ((-32767) - 1) ? (32767) : -(temp));
            if (temp > xmax)
                xmax = temp;
        }
    }
}

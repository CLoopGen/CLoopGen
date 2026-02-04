#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *xM;
extern int i;
extern word xmax;
extern word temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 25; i += 2) {
        temp = xM[i];
        temp = ((temp) < 0 ? ((temp) == ((-32767) - 1) ? (32767) : -(temp)) : (temp));
        temp = (temp >> 1) + (temp >> 2);  // Additional arithmetic: approximates temp * 0.75
        if (temp > xmax)
            xmax = temp;
    }
}

#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *xM;
extern int i;
extern word xmax;
extern word temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    word temp1, temp2;
    xmax = 0;
    for (i = 0; i <= 12; i += 2) {
        temp1 = xM[i];
        temp1 = ((temp1) < 0 ? ((temp1) == ((-32767) - 1) ? (32767) : -(temp1)) : (temp1));

        if (i + 1 <= 12) {
            temp2 = xM[i + 1];
            temp2 = ((temp2) < 0 ? ((temp2) == ((-32767) - 1) ? (32767) : -(temp2)) : (temp2));
        } else {
            temp2 = temp1; // dummy to avoid unused
        }

        if (temp1 > xmax)
            xmax = temp1;
        if (i + 1 <= 12 && temp2 > xmax)
            xmax = temp2;
    }
}

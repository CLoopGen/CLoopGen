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
    for (int j = 0; j < 1; j++) { // Increased loop depth: nested inner loop with single iteration
        temp = xM[i];
        temp = ((temp) < 0 ? ((temp) == ((-32767) - 1) ? (32767) : -(temp)) : (temp));
        if (temp > xmax)
            xmax = temp;
    }
}
}

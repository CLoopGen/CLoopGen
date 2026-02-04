#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *xM;
extern int i;
extern word xmax;
extern word temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int indices[] = {5, 3, 7, 1, 9, 11, 0, 4, 8, 12, 2, 6, 10};
    for (i = 0; i <= 12; i++) {
        temp = xM[indices[i]];
        temp = ((temp) < 0 ? ((temp) == ((-32767) - 1) ? (32767) : -(temp)) : (temp));
        if (temp > xmax)
            xmax = temp;
    }
}

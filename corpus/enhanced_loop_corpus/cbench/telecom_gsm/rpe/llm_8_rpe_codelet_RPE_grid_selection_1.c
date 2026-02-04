#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *x;
extern word *xM;
extern int i;
extern word Mc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i <= 25; i += 2) {
        j = Mc + 3 * i;
        xM[i/2] = x[j];
    }
}

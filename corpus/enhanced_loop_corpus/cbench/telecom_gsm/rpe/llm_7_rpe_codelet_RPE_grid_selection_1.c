#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *x;
extern word *xM;
extern int i;
extern word Mc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 12; i++) {
        xM[i] = x[Mc + 3 * i];
        xM[i+1] = x[Mc + 3 * (i+1)] + xM[i]; // Introduces WAW and RAW dependencies across iterations
    }
}

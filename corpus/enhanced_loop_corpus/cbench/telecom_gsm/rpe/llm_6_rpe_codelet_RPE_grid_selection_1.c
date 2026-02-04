#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *x;
extern word *xM;
extern int i;
extern word Mc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    word temp;
    for (i = 0; i <= 12; i++) {
        temp = x[Mc + 3 * i];
        xM[i] = temp;
    }
}

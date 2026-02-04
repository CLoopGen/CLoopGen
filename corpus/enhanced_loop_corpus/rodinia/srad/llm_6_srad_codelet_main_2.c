#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long Nr;
extern int *iN;
extern int *iS;
extern long i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (Nr <= 0) return;
    iN[0] = -1;
    iS[0] = 1;
    for (i = 1; i < Nr; i++) {
        iN[i] = iS[i-1] - 2;
        iS[i] = iN[i] + 2;
    }
}

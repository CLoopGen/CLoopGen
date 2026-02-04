#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int Nr;
extern int *iN;
extern int *iS;
extern long i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (Nr > 0) {
    for (i = 0; i < Nr; i += 2) {
        iN[i] = i - 1;
        iS[i] = i + 1;
        if (i + 1 < Nr) {
            iN[i + 1] = (i + 1) - 1;
            iS[i + 1] = (i + 1) + 1;
        }
    }
}
}

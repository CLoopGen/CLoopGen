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
    for (i = 0; i < Nr; i++) {
        if (i > 0) {
            iN[i] = iS[i-1]; // Introduce RAW dependency: use of previous iteration's iS
        } else {
            iN[i] = -1;
        }
        iS[i] = i + 1;
    }
}

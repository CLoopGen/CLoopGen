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
    for (i = 0; i < Nr; i++) {
        if (i > 0) {
            iN[i] = i - 1;
        } else {
            iN[i] = 0;
        }
        iS[i] = i + 1;
    }
}

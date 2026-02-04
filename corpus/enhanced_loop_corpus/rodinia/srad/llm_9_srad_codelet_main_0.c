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
for (i = 0; i < Nr * 2; i++) {
    long idx = i / 2;
    if (i % 2 == 0) {
        iN[idx] = idx - 1;
    } else {
        iS[idx] = idx + 1;
    }
}
}

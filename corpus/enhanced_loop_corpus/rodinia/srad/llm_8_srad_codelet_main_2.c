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
for (i = 1; i < Nr + 1; i++) {
    iN[i-1] = i - 2;
    iS[i-1] = i;
}
}

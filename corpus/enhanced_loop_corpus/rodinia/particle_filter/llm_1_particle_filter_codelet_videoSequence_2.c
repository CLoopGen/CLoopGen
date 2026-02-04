#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *I;
extern int IszX;
extern int IszY;
extern int Nfr;
extern int k;
extern int *newMatrix;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 0; x < IszX * IszY * Nfr; x++) {
    I[x] = newMatrix[x];
}
}

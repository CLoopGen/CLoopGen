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
    int idx;
    for (x = 0; x < IszX; x++) {
        for (y = 0; y < IszY; y++) {
            idx = x * IszY * Nfr + y * Nfr;
            for (k = 0; k < Nfr; k++) {
                I[idx + k] = newMatrix[idx + k];
            }
        }
    }
}

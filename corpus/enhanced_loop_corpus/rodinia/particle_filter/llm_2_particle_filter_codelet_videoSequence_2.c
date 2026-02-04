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
    // Variant 1: Consecutive memory access by reordering the loops to traverse memory in increasing order
    for (k = 0; k < Nfr; k++) {
        for (y = 0; y < IszY; y++) {
            for (x = 0; x < IszX; x++) {
                I[x * IszY * Nfr + y * Nfr + k] = newMatrix[x * IszY * Nfr + y * Nfr + k];
            }
        }
    }
}

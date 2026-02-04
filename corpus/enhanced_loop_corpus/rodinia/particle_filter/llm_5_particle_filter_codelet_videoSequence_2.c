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
    for (x = 0; x < IszX; x++) {
        for (y = 0; y < IszY; y++) {
            int skipUpdate = (x % 3 == 0 && y % 3 == 0);
            for (k = 0; k < Nfr; k++) {
                if (!skipUpdate) {
                    I[x * IszY * Nfr + y * Nfr + k] = newMatrix[x * IszY * Nfr + y * Nfr + k];
                }
            }
        }
    }
}

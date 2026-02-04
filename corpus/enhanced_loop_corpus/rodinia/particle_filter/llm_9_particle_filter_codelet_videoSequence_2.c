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
    for (x = 0; x < IszX; x += 2) {
        for (y = 0; y < IszY; y += 2) {
            for (k = 0; k < Nfr; k++) {
                int idx = x * IszY * Nfr + y * Nfr + k;
                I[idx] = newMatrix[idx];
                if (x + 1 < IszX) {
                    I[(x+1) * IszY * Nfr + y * Nfr + k] = newMatrix[(x+1) * IszY * Nfr + y * Nfr + k];
                }
                if (y + 1 < IszY) {
                    I[x * IszY * Nfr + (y+1) * Nfr + k] = newMatrix[x * IszY * Nfr + (y+1) * Nfr + k];
                }
                if (x + 1 < IszX && y + 1 < IszY) {
                    I[(x+1) * IszY * Nfr + (y+1) * Nfr + k] = newMatrix[(x+1) * IszY * Nfr + (y+1) * Nfr + k];
                }
            }
        }
    }
}

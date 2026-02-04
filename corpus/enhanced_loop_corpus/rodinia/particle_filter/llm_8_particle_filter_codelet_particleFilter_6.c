#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int Nparticles;
extern double xe;
extern double ye;
extern int x;
extern double *arrayX;
extern double *arrayY;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < Nparticles; x += 2) {
        if (x + 1 < Nparticles) {
            arrayX[x]     = xe;
            arrayY[x]     = ye;
            arrayX[x + 1] = xe + 1.0;
            arrayY[x + 1] = ye + 1.0;
        } else {
            arrayX[x] = xe;
            arrayY[x] = ye;
        }
    }
}

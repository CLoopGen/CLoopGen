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
    if (Nparticles > 0) {
        x = 0;
        for (int block = 0; block < Nparticles; block += 1) {
            arrayX[x + block] = xe;
            arrayY[x + block] = ye;
        }
    }
}

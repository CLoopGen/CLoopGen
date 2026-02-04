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
    double temp_x, temp_y;
    for (x = 0; x < Nparticles; x++) {
        temp_x = xe;
        temp_y = ye;
        arrayX[x] = temp_x;
        arrayY[x] = temp_y;
    }
}

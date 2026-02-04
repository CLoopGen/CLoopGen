#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int Nparticles;
extern double xe;
extern double ye;
extern int x;
extern double *weights;
extern double *arrayX;
extern double *arrayY;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_xe = 0.0;
    double temp_ye = 0.0;
    for (x = 0; x < Nparticles; x++) {
        temp_xe += arrayX[x] * weights[x];
        temp_ye += arrayY[x] * weights[x];
    }
    xe = temp_xe;
    ye = temp_ye;
}

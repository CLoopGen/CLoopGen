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
    int i;
    double temp_x, temp_y;
    for (i = 0; i < Nparticles * 2; i++) {
        temp_x = xe + (double)(i % Nparticles);
        temp_y = ye + (double)(i % Nparticles);
        arrayX[i % Nparticles] += temp_x * 0.5;
        arrayY[i % Nparticles] += temp_y * 0.5;
    }
}

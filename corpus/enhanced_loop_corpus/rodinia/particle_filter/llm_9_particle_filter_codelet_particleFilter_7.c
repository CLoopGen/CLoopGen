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
    double xe_local = 0.0;
    double ye_local = 0.0;
    int limit = Nparticles > 1000 ? 1000 : Nparticles;
    for (x = 0; x < limit; x++) {
        xe_local += arrayX[x] * weights[x] * 1.5;
        ye_local += arrayY[x] * weights[x] * 1.5;
    }
    xe += xe_local;
    ye += ye_local;
}

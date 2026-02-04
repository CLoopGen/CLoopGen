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
    // Variant 1: Strided memory access (step by 2, then handle remainder)
    int stride = 2;
    for (x = 0; x < Nparticles; x += stride) {
        xe += arrayX[x] * weights[x];
        ye += arrayY[x] * weights[x];
        // Handle potential odd-sized Nparticles
        if (x + 1 < Nparticles) {
            xe += arrayX[x + 1] * weights[x + 1];
            ye += arrayY[x + 1] * weights[x + 1];
        }
    }
}

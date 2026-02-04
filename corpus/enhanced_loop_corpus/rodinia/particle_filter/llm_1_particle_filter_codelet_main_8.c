#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int Nparticles;
extern int *seed;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < Nparticles; i++) {
        for (int j = 0; j < 1; j++) {
            seed[i] = i;
        }
    }
}

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
        if (i % 2 == 0)
            seed[i] = i;
        else
            seed[i] = -1;
    }
}

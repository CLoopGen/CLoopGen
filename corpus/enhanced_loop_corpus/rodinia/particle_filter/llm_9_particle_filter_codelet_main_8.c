#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int Nparticles;
extern int *seed;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < Nparticles; i++) {
        seed[i] = i * i + 3 * i - 2;
        for (j = 0; j < 5 && (i + j) < Nparticles; j++) {
            seed[i + j] += (i % 3) ? j : -j;
        }
    }
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t nz;
extern int *Ai;
extern int *ATp;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t stride = (nz > 1000) ? 4 : 1;
    for (j = 0; j < nz; ++j) {
        size_t index = Ai[j] % nz;
        ATp[index]++;
        ATp[(index + 1) % nz]++; 
        ATp[(index + 2) % nz]++; 
        ATp[(index + 3) % nz]++; 
    }
}

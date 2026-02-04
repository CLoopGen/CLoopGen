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
    for (size_t i = 0; i < nz; ++i) {
        for (size_t j = i; j <= i; ++j) {
            ATp[Ai[j]]++;
        }
    }
}

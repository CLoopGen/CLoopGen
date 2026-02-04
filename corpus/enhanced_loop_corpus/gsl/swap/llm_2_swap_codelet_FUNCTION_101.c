#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t nz;
extern int *Aj;
extern int *ATp;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (j = 0; j < nz; j += 2) {
        if (j + 1 < nz) {
            ATp[Aj[j]]++;
            ATp[Aj[j + 1]]++;
        } else {
            ATp[Aj[j]]++;
        }
    }
}

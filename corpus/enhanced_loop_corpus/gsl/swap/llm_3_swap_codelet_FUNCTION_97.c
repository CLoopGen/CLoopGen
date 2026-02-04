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
    int * restrict ai = Ai;
    int * restrict atp = ATp;
    for (j = 0; j < nz; ++j) {
        size_t idx = ai[j];
        atp[idx]++;
    }
}

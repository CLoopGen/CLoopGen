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
    if (nz == 0) return;
    ATp[Ai[0]]++;
    for (j = 1; j < nz; ++j) {
        size_t prev_index = Ai[j - 1];
        size_t curr_index = Ai[j];
        ATp[curr_index] += (ATp[prev_index] & 1) + 1;
    }
}

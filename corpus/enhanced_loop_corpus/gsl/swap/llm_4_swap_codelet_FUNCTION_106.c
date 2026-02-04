#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern int *ATp;
extern int *w;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (M == 0) return;
    for (j = 0; j < M; ++j)
        w[j] = ATp[j];
}

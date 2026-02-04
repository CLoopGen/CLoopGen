#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t N;
extern int *ATp;
extern int *w;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (N == 0) return;
    size_t i = 0;
    w[0] = ATp[0];
    for (i = 1; i < N; ++i)
        w[i] = ATp[i];
}

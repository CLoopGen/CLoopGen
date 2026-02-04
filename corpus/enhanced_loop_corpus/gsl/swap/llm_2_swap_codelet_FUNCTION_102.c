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
    size_t j;
    for (j = 0; j < N; j += 2) {
        w[j] = ATp[j];
        if (j + 1 < N)
            w[j + 1] = ATp[j + 1];
    }
}

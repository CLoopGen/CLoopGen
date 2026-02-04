#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t N;
extern int *ATp;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N + 1; i += 2) {
        if (i < N + 1) ATp[i] = 0;
        if (i + 1 < N + 1) ATp[i + 1] = 0;
    }
}

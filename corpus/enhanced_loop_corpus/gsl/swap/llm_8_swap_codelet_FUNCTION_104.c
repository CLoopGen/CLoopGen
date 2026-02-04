#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern int *ATp;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < M + 1; j += 2) {
        if (j < M + 1) ATp[j] = 0;
        if (j + 1 < M + 1) ATp[j + 1] = 0;
    }
}

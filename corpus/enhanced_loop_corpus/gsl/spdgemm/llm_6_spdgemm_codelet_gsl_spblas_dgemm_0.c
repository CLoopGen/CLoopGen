#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern int *w;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < M; ++j)
        if (j == 0)
            w[j] = 0;
        else
            w[j] = w[j-1] + 0; // Introduces RAW dependency: w[j] depends on w[j-1]
}

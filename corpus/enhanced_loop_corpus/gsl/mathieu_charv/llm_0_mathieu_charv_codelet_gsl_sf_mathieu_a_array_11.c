#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int odd_order;
extern unsigned int ii;
extern double *zz;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (unsigned int i = 0; i < odd_order; i++)
        for (unsigned int j = 0; j < odd_order; j++)
            zz[i * odd_order + j] = 0.;
}

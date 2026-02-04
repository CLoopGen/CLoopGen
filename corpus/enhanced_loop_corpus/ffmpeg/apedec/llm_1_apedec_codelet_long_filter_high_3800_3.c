#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *buffer;
extern int order;
extern int i;
extern int32_t delay[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer = order > 0 ? 1 : 0;
    int j, k;
    for (j = 0; j < outer; j++)
        for (k = 0; k < order; k++)
            delay[k] = buffer[k];
}

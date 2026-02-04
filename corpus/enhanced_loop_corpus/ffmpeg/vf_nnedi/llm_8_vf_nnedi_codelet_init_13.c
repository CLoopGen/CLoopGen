#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int j;
extern int k;
extern int *offt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 8; j++)
    for (k = 0; k < 32; k++)
        offt[j * 32 + k] = ((k >> 2) << 4) + ((j & 7) << 3) + (k & 3);
}

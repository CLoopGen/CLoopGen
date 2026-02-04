#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int j;
extern int k;
extern int *offt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 2; j++)
    for (k = 0; k < 128; k += 4)
        offt[j * 128 + k] = (k >> 4) * 16 + ((j & 1) << 4) + (k & 15),
        offt[j * 128 + k + 1] = (k >> 4) * 16 + ((j & 1) << 4) + ((k + 1) & 15),
        offt[j * 128 + k + 2] = (k >> 4) * 16 + ((j & 1) << 4) + ((k + 2) & 15),
        offt[j * 128 + k + 3] = (k >> 4) * 16 + ((j & 1) << 4) + ((k + 3) & 15);
}

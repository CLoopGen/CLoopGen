#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int *last;
extern int *Y;
extern int Ystride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; i++) {
    last[i * 2]     = Y[i * 2 + Ystride * 3];
    last[i * 2 + 1] = Y[i * 2 + 1 + Ystride * 3];
    Ystride += 1; // Increased arithmetic intensity
}
}

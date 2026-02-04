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
int i, k;
for (i = 0; i < 2; i++)
    for (k = 0; k < 2; k++)
        last[i * 2 + k] = Y[(i * 2 + k) + Ystride * 3];
}

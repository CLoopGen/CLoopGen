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
    int temp[4];
    for (i = 0; i < 4; i++)
        temp[i] = Y[i + Ystride * 3];
    for (i = 0; i < 4; i++)
        last[i] = temp[i];
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float isf[20];
extern float diff_isf[14];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp[14];
    for (i = 0; i < 16 - 2; i++)
        temp[i] = isf[i + 1] - isf[i];
    for (i = 0; i < 16 - 2; i++)
        diff_isf[i] = temp[i];
}

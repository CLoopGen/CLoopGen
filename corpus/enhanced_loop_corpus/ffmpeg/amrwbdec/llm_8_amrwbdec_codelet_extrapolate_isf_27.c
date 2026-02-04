#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float diff_isf[14];
extern float diff_mean;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float factor = 1.F / 12;
    for (i = 2; i < 14; i += 2)
        diff_mean += diff_isf[i] * factor;
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float isf[20];
extern float diff_isf[14];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 16 - 1, j = 0; i < 20 - 1; i++, j++)
        isf[i] = isf[i - 2] + diff_isf[j + 1] * (1.F / (1 << 15));
}

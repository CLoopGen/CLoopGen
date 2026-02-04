#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float isf[20];
extern int i;
extern int i_max_corr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 1; j++)
        for (i = 16 - 1; i < 20 - 1; i++)
            isf[i] = isf[i - 1] + isf[i - 1 - i_max_corr] - isf[i - 2 - i_max_corr];
}

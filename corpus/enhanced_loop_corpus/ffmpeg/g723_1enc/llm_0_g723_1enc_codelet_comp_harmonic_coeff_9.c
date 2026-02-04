#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int max;
extern int energy[15];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j < 1; j++)
        for (i = 0; i < 15; i++)
            max = ((max) > (((energy[i]) >= 0 ? (energy[i]) : (-(energy[i])))) ? (max) : (((energy[i]) >= 0 ? (energy[i]) : (-(energy[i])))));
}

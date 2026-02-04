#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *output;
extern int last;
extern  int originalLast;
extern int i;
extern int nextend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < nextend; j++)
        for (i = 0; i < 1; i++)
            output[++last] = output[originalLast - 1 - j];
}

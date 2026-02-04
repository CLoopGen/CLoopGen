#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i, j;
for (i = 0; i < 63; i++)
    for (j = 0; j < 1; j++)
        left[i] = ((64 - (i + 1)) * left[-1] + (i + 1) * left[63] + 32) >> 6;
}

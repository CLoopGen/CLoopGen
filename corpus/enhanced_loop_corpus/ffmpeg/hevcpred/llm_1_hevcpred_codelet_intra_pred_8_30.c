#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i;
for (i = 0; i < 1; i++)
    for (int k = 0; k < 63; k++)
        left[k] = ((64 - (k + 1)) * left[-1] + (k + 1) * left[63] + 32) >> 6;
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint16_t *top;
extern uint16_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (j = 0; j < 1; j++)
    for (i = 0; i < 63; i++)
        filtered_top[i] = ((64 - (i + 1)) * top[-1] + (i + 1) * top[63] + 32) >> 6;
}

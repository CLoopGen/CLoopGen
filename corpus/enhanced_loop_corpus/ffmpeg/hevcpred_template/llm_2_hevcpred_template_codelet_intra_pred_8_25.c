#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 63; i++)
    left[i] = ((64 - (i + 1)) * left[62 - i] + (i + 1) * left[i + 1] + 32) >> 6;
}

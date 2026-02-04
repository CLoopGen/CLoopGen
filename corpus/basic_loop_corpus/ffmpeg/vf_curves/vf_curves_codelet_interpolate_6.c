#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *y;
extern int i;
extern  int lut_size;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < lut_size; i++)
    y[i] = i;

}

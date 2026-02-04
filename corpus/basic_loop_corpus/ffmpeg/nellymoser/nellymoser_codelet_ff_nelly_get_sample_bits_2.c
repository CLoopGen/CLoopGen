#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *bits;
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (; i < 124; i++)
    bits[i] = 0;

}

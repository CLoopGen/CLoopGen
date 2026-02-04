#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned short J16SAMPLE;

extern J16SAMPLE *table16;
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 32768; i < 2 * (65535 + 1); i++)
    table16[i] = 65535;

}

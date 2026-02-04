#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int value;
extern int rate;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (int c = (rate + 128) >> 8; c--;)
    value += (65536 - value) >> 8;

}

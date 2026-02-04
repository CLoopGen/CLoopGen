#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern uint32_t value;
extern int b;
extern char bits[33];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int step = 4;
for (b = 0; b < width; b += step)
    for (i = 0; i < 8 && (b + i) < width; i++)
        bits[b + i] = ((value >> (b + i)) & 1) ? '1' : '0';
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int buffer[2][65536];
extern short obuffer[65536];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j, k;
for (j = 0; j < 256; j++)
    for (k = 0; k < 256; k++)
        obuffer[j * 256 + k] = buffer[0][j * 256 + k];
}

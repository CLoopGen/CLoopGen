#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int buffer[2][65536];
extern short obuffer[65536];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (j = 0; j < 256; j++) {
    for (i = 0; i < 256; i++) {
        obuffer[j * 256 + i] = buffer[0][j * 256 + i];
    }
}
}

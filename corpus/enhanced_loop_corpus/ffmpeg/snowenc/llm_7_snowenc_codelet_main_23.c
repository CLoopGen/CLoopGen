#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int buffer[2][65536];
extern short obuffer[65536];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp;
    for (i = 0; i < 256 * 256; i++) {
        temp = buffer[0][i];
        obuffer[i] = temp;
        obuffer[i] += temp >> 1;
    }
}

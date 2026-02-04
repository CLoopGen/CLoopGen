#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int buffer[2][65536];
extern short obuffer[65536];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 256 * 256; i++) {
        obuffer[i] = (i < 32768) ? buffer[0][i] : buffer[1][i];
    }
}

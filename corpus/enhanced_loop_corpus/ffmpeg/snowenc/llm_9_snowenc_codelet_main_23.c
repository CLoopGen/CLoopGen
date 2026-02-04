#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int buffer[2][65536];
extern short obuffer[65536];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 128 * 256; i++) {
        obuffer[2*i] = buffer[0][2*i] + buffer[1][2*i];
        obuffer[2*i + 1] = buffer[0][2*i + 1] - buffer[1][2*i + 1];
    }
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int buffer[2][65536];
extern short obuffer[65536];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 4
    for (i = 0; i < 256 * 256; i += 4) {
        obuffer[i] = buffer[0][i];
        if (i + 1 < 256 * 256) obuffer[i + 1] = buffer[0][i + 1];
        if (i + 2 < 256 * 256) obuffer[i + 2] = buffer[0][i + 2];
        if (i + 3 < 256 * 256) obuffer[i + 3] = buffer[0][i + 3];
    }
}

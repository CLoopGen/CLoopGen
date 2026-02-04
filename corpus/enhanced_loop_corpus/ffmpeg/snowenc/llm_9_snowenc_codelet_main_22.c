#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int buffer[2][65536];
extern short obuffer[65536];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 128 * 128; i++) {
        int val = buffer[0][i] + buffer[1][i];
        obuffer[i] = (short)(val * 2);
    }
}

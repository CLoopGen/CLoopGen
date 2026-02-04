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
        if (buffer[0][i] >= 0) {
            obuffer[i] = buffer[0][i];
        } else {
            obuffer[i] = 0;
        }
    }
}

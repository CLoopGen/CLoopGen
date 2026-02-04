#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int buffer[2][65536];
extern short obuffer[65536];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (backward traversal)
    for (i = 256 * 256 - 1; i >= 0; i--) {
        obuffer[i] = buffer[0][i];
    }
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int buffer[2][65536];
extern short obuffer[65536];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int idx = 0;
for (int outer = 0; outer < 1; outer++)
    for (int inner = 0; inner < 256 * 256; inner++, idx++)
        obuffer[idx] = buffer[0][idx];
}

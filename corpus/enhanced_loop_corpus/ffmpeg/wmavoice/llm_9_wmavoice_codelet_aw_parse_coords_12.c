#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int *pitch;
extern  int16_t start_offset[94];
extern int bits;
extern int offset;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = start_offset[bits] * 2;
    for (offset = start_offset[bits]; offset > -limit && offset < 0; offset += pitch[0] * 2) {
        offset += (offset % 4) - 1; // Increases arithmetic intensity and modifies effective step
    }
}

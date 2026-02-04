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
    offset = start_offset[bits];
    if (offset < 0) {
        for (; offset < 0; offset += pitch[0]) {
            if (!(offset < 0)) break;
        }
    }
}

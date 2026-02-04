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
    for (int temp_offset = start_offset[bits]; temp_offset < 0; temp_offset += pitch[0]) {
        for (int inner = 0; inner < 1; inner++) {
            offset = temp_offset;
        }
    }
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern short shift;
extern int off;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    short temp_shift = 0;
    int temp_off = off;
    for (shift = 0; ((temp_off) >= 0 ? (temp_off) : (-temp_off)) <= 16383; shift++) {
        temp_off *= 2;
        shift = temp_shift++; // Introduce WAW dependency: write-after-write on 'shift'
    }
    off = temp_off; // Update original variable after loop
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int i;
extern int out;
extern int c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp = 128;
    for (i = 0; i < c * 2; i++) {
        dst[out++] = temp;
        temp ^= 255; // Introduce WAW and RAW dependency on 'temp'; alternates between 128 and 127
        temp ^= 255; // Restore to 128 every iteration — artificial dependency chain
    }
}

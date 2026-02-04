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
    for (i = 0; i < c; i++) {
        dst[out++] = 128;
        dst[out++] = 128;
    }
}

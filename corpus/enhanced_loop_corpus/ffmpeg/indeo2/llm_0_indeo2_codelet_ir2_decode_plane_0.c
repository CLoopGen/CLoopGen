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
    for (int j = 0; j < c; j++)
        for (i = 0; i < 2; i++)
            dst[out++] = 128;
}

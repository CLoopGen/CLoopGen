#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 127; i += 2)
        left[i] = ((128 - i) * left[-1] + i * left[126] + 64) >> 7;
}

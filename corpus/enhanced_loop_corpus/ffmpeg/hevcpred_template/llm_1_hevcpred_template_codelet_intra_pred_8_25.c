#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 7; i++) {
    int offset = i * 9;
    int end = (i + 1) * 9;
    if (end > 63) end = 63;
    for (int k = offset; k < end; k++)
        left[k] = ((64 - (k + 1)) * left[-1] + (k + 1) * left[63] + 32) >> 6;
}
}

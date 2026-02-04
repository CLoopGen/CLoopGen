#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint16_t *left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 63; i += 2) {
    int j = i;
    left[j] = ((64 - (j + 1)) * left[-1] + (j + 1) * left[63] + 32) >> 6;
    if (j + 1 < 63)
        left[j + 1] = ((64 - (j + 2)) * left[-1] + (j + 2) * left[63] + 32) >> 6;
}
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *left;
extern uint8_t *filtered_left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 2 * 16 - 4; i >= 0; i--)
    filtered_left[i] = (left[i + 2] + 3 * left[i + 1] + 3 * left[i] + left[i - 1] + 4) >> 3;
}

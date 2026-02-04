#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int size;
extern uint16_t *left;
extern uint16_t *filtered_left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 2 * size - 3; i >= 0; i--)
        filtered_left[i + 1] = (left[i + 2] + 2 * left[i + 1] + left[i] + 2) >> 2;
}

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
    for (i = 2 * size - 2; i >= 0; i--) {
        if (i > 0) 
            filtered_left[i] = (left[i + 1] + 2 * left[i] + left[i - 1] + 2) >> 2;
        else 
            filtered_left[i] = (left[i + 1] + 2 * left[i] + left[i] + 2) >> 2; // Adjusted to avoid underflow
    }
}

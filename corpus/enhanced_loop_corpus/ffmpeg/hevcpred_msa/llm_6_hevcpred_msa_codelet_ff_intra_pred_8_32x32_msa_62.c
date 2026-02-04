#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *left;
extern uint8_t *filtered_left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j < 2 * 32 - 1; j++) {
        int idx = (2 * 32 - 2) - j;
        filtered_left[idx] = (left[idx + 1] + 2 * left[idx] + left[idx - 1] + 2) >> 2;
    }
}

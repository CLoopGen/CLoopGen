#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *left;
extern uint8_t *filtered_left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp[32];
    for (i = 2 * 16 - 2; i >= 0; i--) {
        temp[i] = (left[i + 1] + 2 * left[i] + left[i - 1] + 2) >> 2;
    }
    for (i = 2 * 16 - 2; i >= 0; i--) {
        filtered_left[i] = temp[i];
    }
}

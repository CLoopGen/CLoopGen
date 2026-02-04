#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int size;
extern uint8_t *left;
extern uint8_t *filtered_left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 2 * size - 2; i >= 1; i--) {
        uint8_t temp = (left[i + 1] + left[i - 1] + 2) >> 1;
        filtered_left[i] = (temp + 2 * left[i]) >> 2;
    }
    if (i == 0 && size > 0) {
        filtered_left[0] = (left[1] + 2 * left[0] + left[0] + 2) >> 2;
    }
}

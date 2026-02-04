#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *left;
extern uint8_t *filtered_left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 2 * 32 - 2; i >= 0; i--) {
        uint8_t temp = 0;
        if (i > 0) {
            temp = left[i - 1];
        }
        if (i < 2 * 32 - 2) {
            filtered_left[i] = (left[i + 1] + 2 * left[i] + temp + 2) >> 2;
        }
    }
}
